import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class Solution {
    public static void main(String[] args) {
        int[][] times1 = {
            { 0, 1, 1, 1, 1 },
            { 1, 0, 1, 1, 1 },
            { 1, 1, 0, 1, 1 },
            { 1, 1, 1, 0, 1 },
            { 1, 1, 1, 1, 0 }
        };
        System.out.println(Arrays.toString(solution(times1, 3)));

        int[][] times2 = {
            { 0, 2, 2, 2, -1 },
            { 9, 0, 2, 2, -1 },
            { 9, 3, 0, 2, -1 },
            { 9, 3, 2, 0, -1 },
            { 9, 3, 2, 2, 0 }
        };
        System.out.println(Arrays.toString(solution(times2, 1)));
    }

    public static int INF = 1000000000;

    public static class Edge {
        public int fr, to, c;

        public Edge(int fr, int to, int c) {
            this.fr = fr;
            this.to = to;
            this.c = c;
        }
    }

    static boolean has_negative_cycle(int[][] c) {
        int N = c.length;
        int[] dist = new int[N];
        List<Edge> g = new LinkedList<>();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j)
                    continue;
                g.add(new Edge(i, j, c[i][j]));
            }
        }
        return !bellmanford(g, N, 0, dist);
    }

    static boolean bellmanford(List<Edge> g, int N, int source, int[] dist) {
        Arrays.fill(dist, INF);
        dist[source] = 0;
        int d;
        for (int i = 0; i < N; ++i)
            for (Edge e : g)
                if (dist[e.fr] != INF)
                    if ((d = dist[e.fr] + e.c) < dist[e.to]) {
                        dist[e.to] = d;
                    }
        for (Edge e : g)
            if (dist[e.to] > dist[e.fr] + e.c)
                return false;
        return true;
    }

    public static int[] solution(int[][] times, int time_limit){
        int N = times.length;
        int R = N-2;

        if(has_negative_cycle(times)){
            int[] ret = new int[N-2];
            for(int i = 0; i < ret.length; ++i) ret[i] = i;
            return ret;
        }

        int[][][] DP = new int[N][1<<R][1<<R];
        for(int[][] a : DP) for(int[] b : a) Arrays.fill(b, INF);

        DP[0][(1<<R)-1][0] = 0;

        boolean hasUpdates;
        do {
            hasUpdates = false;
            for(int i = 0; i < N; ++i){
                for(int g = 0; g < (1<<R); ++g){
                    for(int a = 0; a < (1<<R); ++a){
                        if(DP[i][g][a] == INF) continue;
                        for(int j = 0; j < N; ++j){
                            if(i == j) continue;

                            int d = DP[i][g][a]+times[i][j];
                            if     (j == 0  ){ if(d < DP[j][g][a]){ DP[j][g][a] = d; hasUpdates = true; }} // Entrance
                            else if(j == N-1){ // Door
                                if(d <= time_limit) { if(d < DP[j][g][0]){ DP[j][g][0] = d; hasUpdates = true; }} // Can reach door in time
                                else                { if(d < DP[j][g][a]){ DP[j][g][a] = d; hasUpdates = true; }} // Can't reach door in time
                            }
                            else { // Rabbit
                                int rabbitId = j-1;
                                int a_ = a | (g & (1<<rabbitId));
                                int g_ = g & (~a_);
                                if(d < DP[j][g_][a_]){ DP[j][g_][a_] = d; hasUpdates = true; }
                            }
                        }
                    }
                }
            }
        } while(hasUpdates);

        int ret = 0;
        for(int g = 0; g < (1<<R); g++){
            if(DP[N-1][g][0] > time_limit) continue;
            int r = (~g) & ((1<<R)-1);
            if(
                Integer.bitCount(r) > Integer.bitCount(ret) ||
                (
                    Integer.bitCount(r) == Integer.bitCount(ret) &&
                    r < ret
                )
            ) ret = r;
        }

        int[] retArray = new int[Integer.bitCount(ret)];
        int idx = 0;
        for(int i = 0; i < R; ++i){
            if((ret & (1 << i)) != 0){
                retArray[idx++] = i;
            }
        }

        return retArray;
    }
}
