#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int R, C;
    cin >> R >> C;

    // Create and read the grid
    vector<vector<int>> grid(R, vector<int>(C));
    for (int row = 0; row < R; row++) {
        for (int col = 0; col < C; col++) {
            cin >> grid[row][col];
        }
    }

    // Read the specific target cell coordinates
    int targetRow, targetCol;
    cin >> targetRow >> targetCol;

    // 4 Cardinal directions + 4 Diagonal directions = 8 directions total
    int diff[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},           {0, 1},
        {1, -1},  {1, 0},  {1, 1}
    };

    long long sum = 0; // Using long long to prevent integer overflow

    // Check all 8 neighboring directions
    for (int i = 0; i < 8; i++) {
        int adjRow = targetRow + diff[i][0];
        int adjCol = targetCol + diff[i][1];

        // Boundary safety check
        if (adjRow >= 0 && adjRow < R && adjCol >= 0 && adjCol < C) {
            sum += grid[adjRow][adjCol];
        }
    }

    // Output the resulting sum
    cout << sum << "\n";

    return 0;
}
