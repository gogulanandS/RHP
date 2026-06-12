#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int diff[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

void dfs(vector<vector<char>>& grid, int R, int C, int row, int col) {
    grid[row][col] = '0';
    
    for (int i = 0; i < 4; i++) {
        int ar = row + diff[i][0];
        int ac = col + diff[i][1];
        
        if (ar >= 0 && ar < R && ac >= 0 && ac < C && grid[ar][ac] == '1') {
            dfs(grid, R, C, ar, ac);
        }
    }
}
int main() {

    int R, C;
    cin >> R>> C;
    vector<vector<char>> grid(R, vector<char>(C));
    for (int i = 0; i < R; i++) {
        string rowInput;
        cin >> rowInput;
        for (int j = 0; j < C; j++) {
            grid[i][j] = rowInput[j];
        }
    }
    int islands = 0;
    for (int row = 0; row < R; row++) {
        for (int col = 0; col < C; col++) {
            if (grid[row][col] == '1') {
                islands++;
                dfs(grid, R, C, row, col);
            }
        }
    }
    cout<< islands << "\n";
    return 0;
}
