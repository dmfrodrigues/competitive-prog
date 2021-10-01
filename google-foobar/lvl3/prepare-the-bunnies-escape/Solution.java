import java.util.LinkedList;
import java.util.Queue;

public class Solution {
    public static void main(String[] args){
        int[][] m1 = {
            {0, 1, 1, 0},
            {0, 0, 0, 1},
            {1, 1, 0, 0},
            {1, 1, 1, 0}
        };
        System.out.println(solution(m1));
        int[][] m2 = {
            {0, 0, 0, 0, 0, 0},
            {1, 1, 1, 1, 1, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 1, 1, 1, 1, 1},
            {0, 1, 1, 1, 1, 1},
            {0, 0, 0, 0, 0, 0}
        };
        System.out.println(solution(m2));
    }

    static public class Pair<T, U> {
        public T first;
        public U second;
        public Pair(T first, U second){
            this.first = first;
            this.second = second;
        }
    }

    public static int INF = 1000000;

    public static int bfs(int[][] map){
        int I = map.length, J = map[0].length;

        int[][] dist = new int[I][J];
        for(int i = 0; i < I; ++i){
            for(int j = 0; j < J; ++j){
                dist[i][j] = INF;
            }
        }

        Queue<Pair<Integer,Integer>> q = new LinkedList<>();

        dist[0][0] = 1; q.add(new Pair<>(0, 0));

        while(!q.isEmpty()){
            Pair<Integer,Integer> p = q.remove();
            int i = p.first, j = p.second;
            int d = dist[i][j];

            if(i+1 <  I && map[i+1][j] == 0 && dist[i+1][j] == INF){ dist[i+1][j] = d+1; q.add(new Pair<>(i+1, j)); }
            if(i-1 >= 0 && map[i-1][j] == 0 && dist[i-1][j] == INF){ dist[i-1][j] = d+1; q.add(new Pair<>(i-1, j)); }
            if(j+1 <  J && map[i][j+1] == 0 && dist[i][j+1] == INF){ dist[i][j+1] = d+1; q.add(new Pair<>(i, j+1)); }
            if(j-1 >= 0 && map[i][j-1] == 0 && dist[i][j-1] == INF){ dist[i][j-1] = d+1; q.add(new Pair<>(i, j-1)); }
        }

        return dist[I-1][J-1];
    }

    public static int solution(int[][] map){
        int sol = bfs(map);
        int I = map.length, J = map[0].length;
        for(int i = 0; i < I; ++i){
            for(int j = 0; j < J; ++j){
                if(map[i][j] == 1){
                    map[i][j] = 0;
                    int d = bfs(map);
                    sol = Math.min(sol, d);
                    map[i][j] = 1;
                }
            }
        }
        return sol;
    }
}
