#include <bits/stdc++.h>
using namespace std;

// https://www.cs.hmc.edu/~mbrubeck/voronoi.html

// Notation for working with points
typedef pair<double, double> point;
#define x first
#define y second

// Arc, event, and segment datatypes
struct arc;
struct seg;

struct event {
   double x;
   point p;
   arc *a;
   bool valid;

   event(double xx, point pp, arc *aa)
      : x(xx), p(pp), a(aa), valid(true) {}
};

struct arc {
   point p;
   arc *prev, *next;
   event *e;

   seg *s0, *s1;

   arc(point pp, arc *a=0, arc *b=0)
    : p(pp), prev(a), next(b), e(0), s0(0), s1(0) {}
};

vector<seg*> output;  // Array of output segments.

struct seg {
    point _onePoint;
   point start, end;
   bool done;

   seg(point onePoint, point p)
      : _onePoint(onePoint), start(p), end(0,0), done(false)
   { output.push_back(this); }

   // Set the end point and mark as "done."
   void finish(point p) { if (done) return; end = p; done = true; }
};

arc *root = 0; // First item in the parabolic front linked list.

// Function declarations
void process_point();
void process_event();
void front_insert(point  p);

bool circle(point a, point b, point c, double *x, point *o);
void check_circle_event(arc *i, double x0);

bool intersect(point p, arc *i, point *result = 0);
point intersection(point p0, point p1, double l);

void finish_edges();
void print_output();

// "Greater than" comparison, for reverse sorting in priority queue.
struct gt {
   bool operator()(point a, point b) {return a.x==b.x ? a.y>b.y : a.x>b.x;}
   bool operator()(event *a, event *b) {return a->x>b->x;}
};

// Bounding box coordinates.
double X0 = 0, X1 = 0, Y0 = 0, Y1 = 0;

priority_queue<point,  vector<point>,  gt> points; // site events
priority_queue<event*, vector<event*>, gt> events; // circle events

void compute()
{
   // Read points from input.
   X0 = 0; Y0 = 0;
   cin >> X1 >> Y1;
   size_t N; cin >> N;
   point p;
   for(size_t i = 0; i < N; ++i) {
      cin >> p.x >> p.y;
      points.push(p);
   }

   // Process the queues; select the top element with smaller x coordinate.
   while (!points.empty())
      if (!events.empty() && events.top()->x <= points.top().x)
         process_event();
      else
         process_point();

   // After all points are processed, do the remaining circle events.
   while (!events.empty())
      process_event();

   finish_edges(); // Clean up dangling edges.
   // print_output(); // Output the voronoi diagram.
}

void process_point()
{
   // Get the next point from the queue.
   point p = points.top();
   points.pop();

   // Add a new arc to the parabolic front.
   front_insert(p);
}

void process_event()
{
   // Get the next event from the queue.
   event *e = events.top();
   events.pop();

   if (e->valid) {
      // Remove the associated arc from the front.
      arc *a = e->a;

      // Start a new edge.
      seg *s = new seg(a->p, e->p);

      if (a->prev) {
         a->prev->next = a->next;
         a->prev->s1 = s;
      }
      if (a->next) {
         a->next->prev = a->prev;
         a->next->s0 = s;
      }

      // Finish the edges before and after a.
      if (a->s0) a->s0->finish(e->p);
      if (a->s1) a->s1->finish(e->p);

      // Recheck circle events on either side of p:
      if (a->prev) check_circle_event(a->prev, e->x);
      if (a->next) check_circle_event(a->next, e->x);
   }
   delete e;
}

void front_insert(point p)
{
   if (!root) {
      root = new arc(p);
      return;
   }

   // Find the current arc(s) at height p.y (if there are any).
   for (arc *i = root; i; i = i->next) {
      point z, zz;
      if (intersect(p,i,&z)) {
         // New parabola intersects arc i.  If necessary, duplicate i.
         if (i->next && !intersect(p,i->next, &zz)) {
            i->next->prev = new arc(i->p,i,i->next);
            i->next = i->next->prev;
         }
         else i->next = new arc(i->p,i);
         i->next->s1 = i->s1;

         // Add p between i and i->next.
         i->next->prev = new arc(p,i,i->next);
         i->next = i->next->prev;

         i = i->next; // Now i points to the new arc.

         // Add new half-edges connected to i's endpoints.
         i->prev->s1 = i->s0 = new seg(p, z);
         i->next->s0 = i->s1 = new seg(p, z);

         // Check for new circle events around the new arc:
         check_circle_event(i, p.x);
         check_circle_event(i->prev, p.x);
         check_circle_event(i->next, p.x);

         return;
      }
   }

   // Special case: If p never intersects an arc, append it to the list.
   arc *i;
   for (i = root; i->next; i=i->next) ; // Find the last node.

   i->next = new arc(p,i);
   // Insert segment between p and i
   point start;
   start.x = X0;
   start.y = (i->next->p.y + i->p.y) / 2;
   i->s1 = i->next->s0 = new seg(p, start);
}

// Look for a new circle event for arc i.
void check_circle_event(arc *i, double x0)
{
   // Invalidate any old event.
   if (i->e && i->e->x != x0)
      i->e->valid = false;
   i->e = NULL;

   if (!i->prev || !i->next)
      return;

   double x;
   point o;

   if (circle(i->prev->p, i->p, i->next->p, &x,&o) && x > x0) {
      // Create new event.
      i->e = new event(x, o, i);
      events.push(i->e);
   }
}

// Find the rightmost point on the circle through a,b,c.
bool circle(point a, point b, point c, double *x, point *o)
{
   // Check that bc is a "right turn" from ab.
   if ((b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y) > 0)
      return false;

   // Algorithm from O'Rourke 2ed p. 189.
   double A = b.x - a.x,  B = b.y - a.y,
          C = c.x - a.x,  D = c.y - a.y,
          E = A*(a.x+b.x) + B*(a.y+b.y),
          F = C*(a.x+c.x) + D*(a.y+c.y),
          G = 2*(A*(c.y-b.y) - B*(c.x-b.x));

   if (G == 0) return false;  // Points are co-linear.

   // Point o is the center of the circle.
   o->x = (D*E-B*F)/G;
   o->y = (A*F-C*E)/G;

   // o.x plus radius equals max x coordinate.
   *x = o->x + sqrt( pow(a.x - o->x, 2) + pow(a.y - o->y, 2) );
   return true;
}

// Will a new parabola at point p intersect with arc i?
bool intersect(point p, arc *i, point *res)
{
   if (i->p.x == p.x) return false;

   double a,b;
   if (i->prev) // Get the intersection of i->prev, i.
      a = intersection(i->prev->p, i->p, p.x).y;
   if (i->next) // Get the intersection of i->next, i.
      b = intersection(i->p, i->next->p, p.x).y;

   if ((!i->prev || a <= p.y) && (!i->next || p.y <= b)) {
      res->y = p.y;

      // Plug it back into the parabola equation.
      res->x = (i->p.x*i->p.x + (i->p.y-res->y)*(i->p.y-res->y) - p.x*p.x)
                / (2*i->p.x - 2*p.x);

      return true;
   }
   return false;
}

// Where do two parabolas intersect?
point intersection(point p0, point p1, double l)
{
   point res, p = p0;

   if (p0.x == p1.x)
      res.y = (p0.y + p1.y) / 2;
   else if (p1.x == l)
      res.y = p1.y;
   else if (p0.x == l) {
      res.y = p0.y;
      p = p1;
   } else {
      // Use the quadratic formula.
      double z0 = 2*(p0.x - l);
      double z1 = 2*(p1.x - l);

      double a = 1/z0 - 1/z1;
      double b = -2*(p0.y/z0 - p1.y/z1);
      double c = (p0.y*p0.y + p0.x*p0.x - l*l)/z0
               - (p1.y*p1.y + p1.x*p1.x - l*l)/z1;

      res.y = ( -b - sqrt(b*b - 4*a*c) ) / (2*a);
   }
   // Plug back into one of the parabola equations.
   res.x = (p.x*p.x + (p.y-res.y)*(p.y-res.y) - l*l)/(2*p.x-2*l);
   return res;
}

void finish_edges()
{
   // Advance the sweep line so no parabolas can cross the bounding box.
   double l = X1 + (X1-X0) + (Y1-Y0);

   // Extend each remaining segment to the new parabola intersections.
   for (arc *i = root; i->next; i = i->next)
      if (i->s1)
         i->s1->finish(intersection(i->p, i->next->p, l*2));
}

void print_output()
{
   // Bounding box coordinates.
//    cout << X0 << " "<< X1 << " " << Y0 << " " << Y1 << endl;

   // Each output segment in four-column format.
   vector<seg*>::iterator i;
   for (i = output.begin(); i != output.end(); i++) {
      point p0 = (*i)->start;
      point p1 = (*i)->end;
      point p = (*i)->_onePoint;
      cout << p0.x << " " << p0.y << " " << p1.x << " " << p1.y << "(" << p.x << " " << p.y << ")" << endl;
   }
}

double dist(point p1, point p2){
    double dx = p2.x-p1.x, dy = p2.y-p1.y;
    return sqrt(dx*dx + dy*dy);
}

double dist_line(point p1, point p2, point p){
    double x0 = p.x, y0 = p.y;
    double x1 = p1.x, x2 = p2.x, y1 = p1.y, y2 = p2.y;

    double prod1 = (x2-x1)*(x0-x1)+(y2-y1)*(y0-y1);
    double prod2 = (x1-x2)*(x0-x2)+(y1-y2)*(y0-y2);

    if(prod1 < 0 || prod2 < 0) return min(dist(p1, p), dist(p2, p));

    double d = fabs((x2-x1)*(y1-y0)-(x1-x0)*(y2-y1))/dist(p1, p2);
    return d;
}

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 

int main(){
    compute();
    unordered_map<point, unordered_map<point, double, hash_pair>, hash_pair> adj;
    for(size_t i = 0; i < output.size(); ++i){
        const auto &s = output[i];
        adj[s->start][s->end] = dist_line(s->start, s->end, s->_onePoint);
        adj[s->end][s->start] = dist_line(s->start, s->end, s->_onePoint);
    }
    cout << adj.size() << endl;
    pair<point,point> start_edge, end_edge; double start_dist = X1*Y1, end_dist = X1*Y1;
    for(size_t i = 0; i < output.size(); ++i){
        point p1 = output[i]->start, p2 = output[i]->end;
        double d;
        d = dist_line(p1, p2, point(0,0));
        if(d < start_dist) { start_edge = pair(p1, p2); start_dist = d; }
        d = dist_line(p1, p2, point(X1,Y1));
        if(d < end_dist  ) { end_edge   = pair(p1, p2); end_dist   = d; }
    }
    
}
