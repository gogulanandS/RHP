#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cout << "Enter number of rows (n) and columns (m): ";
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    queue<pair<int, int>> q;
    int oranges = 0;

    cout << "Enter the grid elements (0 = Empty, 1 = Fresh, 2 = Rotten):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] != 0) {
                oranges++;
            }
            if (grid[i][j] == 2) {
                q.push(make_pair(i, j));
                grid[i][j] = 0; // Mark visited/processed
            }
        }
    }

    if (oranges == 0) {
        cout << "Minutes until all rotting: 0" << endl;
        return 0;
    }

    // Direction array for moving Left, Up, Right, Down
    int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}}; 
    int min_time = -1;

    while (!q.empty()) {
        oranges -= q.size();
        int qsize = q.size();
        
        while (qsize--) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for (int k = 0; k < 4; k++) {
                int ar = r + dir[k][0];
                int ac = c + dir[k][1];
                
                if (ar >= 0 && ar < n && ac >= 0 && ac < m && grid[ar][ac] == 1) {
                    grid[ar][ac] = 2;
                    q.push(make_pair(ar, ac));
                }
            }
        }
        min_time++;
    }

    int result = (oranges == 0) ? min_time : -1;
    cout << "Minutes until all rotting: " << result << endl;

    return 0;
}
