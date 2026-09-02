#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canCross(int row, int col, const vector<vector<int>>& cells, int day) {
        vector<vector<int>> grid(row, vector<int>(col, 0));
        
        // Fill the grid with water up to the given day
        // Cells are 1-indexed in the input, convert to 0-indexed
        for (int i = 0; i < day; i++) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = 1;
        }

        queue<pair<int, int>> q;
        vector<vector<bool>> vis(row, vector<bool>(col, false));

        // Add all walkability entry points on the first row
        for (int j = 0; j < col; j++) {
            if (grid[0][j] == 0) {
                q.push({0, j});
                vis[0][j] = true;
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            // If we successfully reached the last row, we can cross
            if (r == row - 1) {
                return true;
            }

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < row && nc >= 0 && nc < col && !vis[nr][nc] && grid[nr][nc] == 0) {
                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 1;
        int right = row * col;
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canCross(row, col, cells, mid)) {
                ans = mid;
                left = mid + 1; // Try to find a later day
            } else {
                right = mid - 1; // Try an earlier day
            }
        }
        return ans;
    }
};

int main() {
    int row, col;
    cout << "Enter number of rows and columns: ";
    cin >> row >> col;

    int totalCells = row * col;
    vector<vector<int>> cells(totalCells, vector<int>(2));

    cout << "Enter " << totalCells << " cell coordinates (1-indexed row and col):\n";
    for (int i = 0; i < totalCells; i++) {
        cin >> cells[i][0] >> cells[i][1];
    }

    Solution sol;
    int day = sol.latestDayToCross(row, col, cells);

    cout << "\nThe latest day you can completely cross is: " << day << endl;

    return 0;
}
