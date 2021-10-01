import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;

public class Solution {
    public static void main(String[] args){
        int[] in1  = {0, 1};
        int[] out1 = {4, 5};
        int[][] p1 = {
            {0, 0, 4, 6, 0, 0},
            {0, 0, 5, 2, 0, 0},
            {0, 0, 0, 0, 4, 4},
            {0, 0, 0, 0, 6, 6},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0}
        };
        System.out.println(solution(in1, out1, p1));

        int[] in2  = {0};
        int[] out2 = {3};
        int[][] p2 = {
            {0, 7, 0, 0},
            {0, 0, 6, 0},
            {0, 0, 0, 8},
            {9, 0, 0, 0}
        };
        System.out.println(solution(in2, out2, p2));
    }

    public static int INF = 1000000000;

    public static class FlowGraph {
        public Set<Integer>[] adj; int[][] cap;
        public FlowGraph(int s){
            adj = new HashSet[s]; for(int i = 0; i < s; ++i) adj[i] = new HashSet<Integer>();
            cap = new int[s][s];     for(int i = 0; i < s; ++i) Arrays.fill(cap[i], 0);
        }
        public void addEdge(int src, int dst) { addEdge(src, dst, 0); }
        public void addEdge(int src, int dst, int c) {
            adj[src].add(dst); cap[src][dst] += c;
            adj[dst].add(src);
        }
        public int size() { return adj.length; }
    };
        

    public static boolean bfs_dinic(FlowGraph g, int[] prev, int s, int t){
        Arrays.fill(prev, -1); Queue<Integer> q = new LinkedList<>();
        prev[s] = -2; q.add(s);
        while(!q.isEmpty() && prev[t] == -1){
            int u = q.remove();
            for(int v:g.adj[u]){
                if(prev[v] == -1 && g.cap[u][v] != 0){
                    prev[v] = u; q.add(v);
                }
            }
        } return (prev[t] != -1);
    }
    public static int dinic(FlowGraph g, int s, int t) {
        int f = 0;
        int[] prev = new int[g.size()];
        while(bfs_dinic(g,prev,s,t)){
            int f_ = INF; //Go back and see how much we can increase flow
            for(int v = t; prev[v] >= 0; v = prev[v])
                { f_ = Math.min(f_, g.cap[prev[v]][v]); }
            for(int v = t; prev[v] >= 0; v = prev[v])
                { g.cap[prev[v]][v] -= f_; g.cap[v][prev[v]] += f_; }
            f += f_;
        }
        return f;
    }    

    public static int solution(int[] entrances, int[] exits, int[][] path){
        int N = path.length;

        FlowGraph G = new FlowGraph(N+2);
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(path[i][j] != 0){
                    G.addEdge(i, j, path[i][j]);
                }
            }
        }

        for(int entrance: entrances) G.addEdge(N, entrance, INF); // Node N is the virtual source
        for(int exit    : exits    ) G.addEdge(exit, N+1  , INF); // Node N+1 is the virtual sink

        return dinic(G, N, N+1);
    }
}
