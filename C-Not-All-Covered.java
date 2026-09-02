import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();

        // Difference array
        int[] diff = new int[N + 2];

        // Read all intervals
        for (int i = 0; i < M; i++) {
            int L = sc.nextInt();
            int R = sc.nextInt();

            diff[L]++;       // Coverage starts
            diff[R + 1]--;   // Coverage ends after R
        }

        int coverage = 0;
        int answer = Integer.MAX_VALUE;

        // Prefix Sum
        for (int i = 1; i <= N; i++) {
            coverage += diff[i];
            answer = Math.min(answer, coverage);
        }

        System.out.println(answer);
    }
}