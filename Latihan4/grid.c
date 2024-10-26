#include <stdio.h>

#define MOD 1000000007

int grid[1001][1001];
int dp[1001][1001];

int main() {
    int N;
    
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    if (grid[0][0] == 0) {
        dp[0][0] = 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 1) {
                dp[i][j] = 0; 
            } else {

                if (i > 0) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
                }

                if (j > 0) {
                    dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
                }
            }
        }
    }


    printf("%d\n", dp[N-1][N-1]);
    
    return 0;
}
