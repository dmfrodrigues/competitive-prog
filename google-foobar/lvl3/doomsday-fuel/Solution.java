import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.stream.IntStream;

public class Solution {
    public static void main(String[] args){
        int[][] m = {
            {0, 2, 1, 0, 0},
            {0, 0, 0, 3, 4},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0,0},
            {0, 0, 0, 0, 0}
        };
        System.out.println(Arrays.toString(solution(m)));
        int[][] n = {
            {0, 1, 0, 0, 0, 1},
            {4, 0, 0, 3, 2, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0}
        };
        System.out.println(Arrays.toString(solution(n)));
        int[][] p = {
            {0, 0, 0, 0, 0, 0},
            {4, 0, 0, 3, 2, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0}
        };
        System.out.println(Arrays.toString(solution(p)));
        int[][] q = {
            {0}
        };
        System.out.println(Arrays.toString(solution(q)));

        // Fraction[][] A = {
        //     {new Fraction(2), new Fraction(-1), new Fraction(0)},
        //     {new Fraction(-1), new Fraction(2), new Fraction(-1)},
        //     {new Fraction(0), new Fraction(-1), new Fraction(2)}
        // };
        // Matrix.print(A);
        // Fraction[][] B = Matrix.gauss_jordan_elimination(A);
        // Matrix.print(B);
    }

    public static long gcd(long a, long b){
        if(b != 0) return gcd(b, a%b); else return a;
    }

    public static long lcm(long a, long b){
        return (a*b)/gcd(a, b);
    }

    public static class Fraction {
        long num, div;

        private void fix_negative_div(){
            if(div < 0){
                div = -div;
                num = -num;
            }
        }

        public Fraction(long num){
            set(num, 1);
        }
        public Fraction(long num, long div){
            set(num, div);
        }
        public void set(long num, long div){
            this.num = num;
            this.div = div;
            fix_negative_div();
            reduce();
        }

        public void reduce(){
            if(num == 0){
                div = 1;
            } else {
                long d = gcd(Math.abs(num), Math.abs(div));
                num /= d;
                div /= d;
            }
        }

        void mult(long l){
            num *= l;
            div *= l;
        }

        public Fraction multiply(Fraction f) {
            return new Fraction(num * f.num, div * f.div);
        }
        public Fraction divide(Fraction f) {
            return new Fraction(num * f.div, div * f.num);
        }
        public Fraction multiply_inplace(Fraction f){
            num *= f.num;
            div *= f.div;
            reduce();
            return this;
        }
        public Fraction divide_inplace(Fraction f){
            long num1 = f.num;
            num *= f.div;
            div *= num1;
            fix_negative_div();
            reduce();
            return this;
        }
        public Fraction add(Fraction f) {
            Fraction f1 = this; f1.reduce();
            Fraction f2 = f; f2.reduce();
            long l = lcm(f1.div, f2.div);
            return new Fraction(f1.num*l/f1.div + f2.num*l/f2.div, l);
        }
        public Fraction subtract(Fraction f) {
            Fraction f1 = this; f1.reduce();
            Fraction f2 = f; f2.reduce();
            long l = lcm(f1.div, f2.div);
            assert(f1.div != 0);
            assert(f2.div != 0);
            return new Fraction((f1.num*l/f1.div) - (f2.num*l/f2.div), l);
        }
        public Fraction add_inplace(Fraction f){
            Fraction f1 = this.add(f);
            num = f1.num;
            div = f1.div;
            return this;
        }
        public Fraction substract_inplace(Fraction f){
            Fraction f1 = this.subtract(f);
            num = f1.num;
            div = f1.div;
            return this;
        }
    }

    public static class Matrix {
        public static Fraction[][] identity(int n){
            Fraction[][] ret = new Fraction[n][n];
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    ret[i][j] = new Fraction((i == j ? 1 : 0));
            return ret;
        }

        public static Fraction[][] subtract(Fraction[][] lhs, Fraction[][] rhs){
            if(lhs.length == 0 && rhs.length == 0) return new Fraction[0][0];

            int M = lhs.length;
            int N = lhs[0].length;

            assert(rhs.length == M);
            for(int i = 0; i < M; ++i){
                assert(lhs[i].length == N);
                assert(rhs[i].length == N);
            }

            Fraction[][] ret = new Fraction[M][N];
            for(int i = 0; i < M; ++i){
                for(int j = 0; j < N; ++j){
                    ret[i][j] = lhs[i][j].subtract(rhs[i][j]);
                }
            }

            return ret;
        }

        public static Fraction[][] multiply(Fraction[][] A, Fraction[][] B){
            if(A.length == 0 && B.length == 0) return new Fraction[0][0];

            int M = A.length;
            int N = A[0].length;
            int P = B[0].length;

            for(int i = 0; i < M; ++i) assert(A[i].length == N);
            assert(B.length == N);
            for(int i = 0; i < N; ++i) assert(B[i].length == P);

            Fraction[][] C = new Fraction[M][P];
            for(int i = 0; i < M; ++i){
                for(int j = 0; j < P; ++j){
                    C[i][j] = new Fraction(0);
                    for(int k = 0; k < N; ++k){
                        C[i][j].add_inplace(A[i][k].multiply(B[k][j]));
                    }
                }
            }

            return C;
        }

        public static Fraction[][] invert(Fraction[][] M){
            return gauss_jordan_elimination(M);
        }

        public static Fraction[][] gauss_jordan_elimination(Fraction[][] A){
            int N = A.length;
            for(int i = 0; i < N; ++i) assert(A[i].length == N);

            Fraction[][] R = Matrix.identity(N);

            for(int i = 0; i < N; ++i){
                for(int j = 0; j < N; ++j) R[i][j].divide_inplace(A[i][i]);      // Divide Rij by Aii
                for(int j = N-1; j >= i; --j) A[i][j].divide_inplace(A[i][i]);   // Divide values to right of Aii by Aii

                for(int i_ = i+1; i_ < N; ++i_){                                 // Zero out values below Aii
                    for(int j = 0; j < N; ++j) R[i_][j].substract_inplace(R[i][j].multiply(A[i_][i]));
                    for(int j = N-1; j >= i; --j) A[i_][j].substract_inplace(A[i][j].multiply(A[i_][i]));
                }
            }

            for(int i = N-1; i >= 0; --i){
                for(int i_ = 0; i_ < i; ++i_){         // Zero out values above Aii
                    for(int j = 0; j < N; ++j) R[i_][j].substract_inplace(A[i_][i].multiply(R[i][j]));
                    A[i_][i].substract_inplace(A[i_][i].multiply(A[i][i]));
                }
            }

            return R;
        }

        public static void print(Fraction[][] M){
            System.out.println("[");
            for(int i = 0; i < M.length; ++i) System.out.println(Arrays.toString(M[i]));
            System.out.println("]");
        }

        public static void print(int[][] M){
            System.out.println("[");
            for(int i = 0; i < M.length; ++i) System.out.println(Arrays.toString(M[i]));
            System.out.println("]");
        }
    }

    public static int[] solution(int[][] m){
        int N = m.length;

        List<Integer> non_absorbing = new LinkedList<>();
        List<Integer> absorbing = new LinkedList<>();
        for(int i = 0; i < N; ++i){
            int s = IntStream.of(m[i]).sum();
            if(s == 0){
                absorbing.add(i);
            }
            else non_absorbing.add(i);
        }

        int[] original2processed = new int[N];
        int[] processed2original = new int[N];
        for(int i = 0; i < non_absorbing.size(); ++i){
            int p = i;
            int o = non_absorbing.get(i);
            original2processed[o] = p;
            processed2original[p] = o;
        }
        for(int i = 0; i < absorbing.size(); ++i){
            int p = non_absorbing.size() + i;
            int o = absorbing.get(i);
            original2processed[o] = p;
            processed2original[p] = o;
        }

        int source = original2processed[0];
        
        int[][] newM = new int[N][N];
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                newM[i][j] = m[processed2original[i]][processed2original[j]];
            }
        }

        return solution2(newM, non_absorbing.size(), source);
    }

    public static int[] solution2(int[][] m, int t, int source){
        int n = m.length;
        int s = n-t;

        if(source >= t){
            int[] ret = new int[s+1];
            ret[0] = 1;
            ret[s] = 1;
            return ret;
        }

        // Create matrix P
        Fraction P[][] = new Fraction[n][n];
        for(int i = 0; i < n; ++i){
            int sum = IntStream.of(m[i]).sum();
            if(sum == 0){
                m[i][i] = 1;
                sum = 1;
            }
            for(int j = 0; j < n; ++j){
                P[i][j] = new Fraction(m[i][j], sum);
            }
        }

        /*
         * From https://brilliant.org/wiki/absorbing-markov-chains/, if we move all absorbing
         * states to the last indexes, we can decompose the transition probability matrix into
         * 
         * P = | Q  R  |
         *     | 0  Is |
         * 
         * Where Q is a t*t matrix, R is a t*s matrix, 0 is the s*t zero matrix, and
         * Is is an s*s identity matrix.
         */

        Fraction[][] Q = new Fraction[t][t];
        for(int i = 0; i < Q.length; ++i) for(int j = 0; j < Q[i].length; ++j) Q[i][j] = P[i][j];

        Fraction[][] R = new Fraction[t][s];
        for(int i = 0; i < R.length; ++i) for(int j = 0; j < R[i].length; ++j) R[i][j] = P[i][t+j];

        Fraction[][] It = Matrix.identity(t);

        /*
         * N = (It - Q)^(-1) = \sum_{k=0}^{\infty}{Q^k} is the fundamental matrix. It contains a lot
         * of information that is very useful; take the following example, meant only for empirical
         * comprehension:
         * 
         * A -> B -> D
         *     / ^
         *     \ \
         *     v /
         *      C -> E
         * 
         * (A->B, B->C, C->B, B->D, C->E). Say a is the prob. of transition B->D,
         * and b is the prob. of transition C->E. The probability of being absorbed by D
         * when starting in A is:
         * 
         * p =
         *      1                 * a + // Cycle not traversed
         *      (1-a)   * (1-b)   * a + // Cycle traversed once
         *      (1-a)^2 * (1-b)^2 * a + // Cycle traversed twice
         *      ...
         * = a * \sum_{k=0}^{\infty}{(1-a)^i * (1-b)^i}
         * 
         * so inverting (It-Q) is a cheap alternative to making an infinite sum :)
         */

        Fraction[][] N = Matrix.invert(Matrix.subtract(It, Q));

        /*
         * The probability of being absorbed by state j after starting in state i is given by M[i][j],
         * where matrix M is given by:
         * 
         * M = N * R
         */

        Fraction[][] M = Matrix.multiply(N, R);
        
        Fraction[] retFrac = M[source];
        for(int i = 0; i < retFrac.length; ++i){
            retFrac[i].fix_negative_div();
            retFrac[i].reduce();
        }

        long l = 1;
        for(int i = 0; i < retFrac.length; ++i) l = lcm(l, retFrac[i].div);

        int[] ret = new int[retFrac.length+1];
        for(int i = 0; i < retFrac.length; ++i)
            ret[i] = (int)(retFrac[i].num * (l/retFrac[i].div));
        ret[retFrac.length] = (int)(l);

        return ret;
    }
}
