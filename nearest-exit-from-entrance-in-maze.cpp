#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size();
        int columns = maze[0].size();

        // Queue holds pairs of {row, col} indices
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        
        // Mark the entrance as visited
        maze[entrance[0]][entrance[1]] = '+';

        int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int steps = 0;

        while (!q.empty()) {
            steps++;
            int n = q.size();

            for (int i = 0; i < n; i++) {
                auto [currX, currY] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int x = currX + directions[k][0];
                    int y = currY + directions[k][1];

                    // Out of bounds check
                    if (x < 0 || x >= rows || y < 0 || y >= columns) continue;
                    // Wall or visited check
                    if (maze[x][y] == '+') continue;

                    // If it is on the boundary, it is an exit
                    if (x == 0 || x == rows - 1 || y == 0 || y == columns - 1) {
                        return steps;
                    }

                    // Mark as visited and push to queue
                    maze[x][y] = '+';
                    q.push({x, y});
                }
            }
        }
        return -1;
    }
};

int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns for the maze: ";
    cin >> rows >> cols;

    if (rows <= 0 || cols <= 0) {
        cout << "Invalid maze dimensions." << endl;
        return 0;
    }

    vector<vector<char>> maze(rows, vector<char>(cols));
    cout << "Enter the maze grid row by row ('.' for empty space, '+' for walls):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> maze[i][j];
        }
    }

    vector<int> entrance(2);
    cout << "Enter entrance coordinates (row and column index): ";
    cin >> entrance[0] >> entrance[1];

    Solution sol;
    int result = sol.nearestExit(maze, entrance);

    if (result != -1) {
        cout << "\nThe minimum number of steps to reach the nearest exit is: " << result << endl;
    } else {
        cout << "\nNo exit is reachable from the given entrance (-1)." << endl;
    }

    return 0;
}
