#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool found = false;

    void dfs(vector<vector<bool>>& temp, vector<vector<int>>& grid, int n,
             int m, int i, int j, int islnd) {
        temp[i][j] = false; // Using boolean false instead of 0
        grid[i][j] = islnd;
        for (int k = 0; k < 4; k++) {
            int ar = i + dir[k][0], ac = j + dir[k][1];
            if (ar < n && ac < m && ac >= 0 && ar >= 0 && temp[ar][ac]) {
                dfs(temp, grid, n, m, ar, ac, islnd);
            }
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int n = grid.size(), m = grid[0].size(), island = 0;
        vector<vector<bool>> temp(n, vector<bool>(m));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                temp[i][j] = grid[i][j];
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (temp[i][j]) {
                    island++;
                    dfs(temp, grid, n, m, i, j, island);
                }
            }
        }
        
        if (island == 0) return 1;
        
        int maxi = 0;
        vector<int> v(island + 1, 0);
        for (auto& a : grid) {
            for (int& x : a) {
                if (x <= island) {
                    v[x]++;
                }
            }
        }
        
        for (int i = 1; i < v.size(); i++) {
            maxi = max(maxi, v[i]);
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> unique_islands;
                    for (int k = 0; k < 4; k++) {
                        int ar = i + dir[k][0], ac = j + dir[k][1];
                        if (ar < n && ac < m && ac >= 0 && ar >= 0 && grid[ar][ac] != 0) {
                            unique_islands.insert(grid[ar][ac]);
                        }
                    }
                    int sum = 1;
                    for (int x : unique_islands) {
                        sum += v[x];
                    }
                    maxi = max(sum, maxi);
                }
            }
        }
        return maxi;
    }
};

int main() {
    int n, m;
    cout << "Enter the grid dimensions (Rows and Columns): ";
    cin >> n >> m;

    if (n <= 0 || m <= 0) {
        cout << "Invalid grid dimensions." << endl;
        return 0;
    }

    vector<vector<int>> grid(n, vector<int>(m));
    cout << "Enter the grid elements row by row (0 for water, 1 for land):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    Solution sol;
    int ans = sol.largestIsland(grid);

    cout << "\nThe maximum area of an island after changing at most one 0 to 1 is: " << ans << endl;

    return 0;
}
