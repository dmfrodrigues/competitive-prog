import java.util.stream.IntStream;

public class Solution {
    public static void main(String[] args){
        System.out.println(solution(3));
        System.out.println(solution(200));
    }

    public static int solution(int N){
        int[][] DP = new int[N+1][N];
        for(int i = 0; i <= N; ++i)
            for(int j = 0; j < N; ++j)
                DP[i][j] = 0;
        
        for(int i = 1; i < N; ++i){
            for(int j = i+1; i+j <= N; ++j){
                DP[i+j][j] += 1;
            }
        }

        for(int n = 0; n <= N; ++n){
            for(int h = 0; h < N; ++h){
                for(int i = h+1; i <= Math.min(N-n, N-1); ++i){
                    DP[n+i][i] += DP[n][h];
                }
            }
        }

        return IntStream.of(DP[N]).sum();
    }
}
