#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 4 directions: left, right, up, down
const int diff[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int R, int C, int row, int col) {
    // Base condition / Memoization check
    if (dp[row][col] != 0) {
        return dp[row][col];
    }

    int adjMax = 0;
    for (int i = 0; i < 4; i++) {
        int ar = row + diff[i][0];
        int ac = col + diff[i][1];
        
        // Move only if the neighbor is within boundaries and has a strictly GREATER value
        if (ar >= 0 && ar < R && ac >= 0 && ac < C && matrix[ar][ac] > matrix[row][col]) {
            adjMax = max(adjMax, dfs(matrix, dp, R, C, ar, ac));
        }
    }

    // Save result to DP table and return
    dp[row][col] = 1 + adjMax;
    return dp[row][col];
}

int main() {
    int R, C;
    cin >> R >> C;

    vector<vector<int>> matrix(R, vector<int>(C)),dp(R, vector<int>(C, 0));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> matrix[i][j];
        }
    }

    int maxlen = 0; // Tracks global longest path length

    // Core application logic integrated into main
    for (int row = 0; row < R; row++) {
        for (int col = 0; col < C; col++) {
            // Unvisited cell
            if (dp[row][col] == 0) {
                maxlen = max(maxlen, dfs(matrix, dp, R, C, row, col));
            }
        }
    }

    cout << maxlen << "\n";

    return 0;
}
