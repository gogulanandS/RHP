#include<iostream>
#include<vector>
using namespace std;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool f = false;

    void dfs(vector<vector<char>>& board, string word, int j, int i, int c,
             int r, int idx) {
        if (idx == word.size() - 1) {
            f = true;
            return;
        }

        auto backup = board[i][j];
        board[i][j] = '.';
        for (int k = 0; k < 4; k++) {
            int ac = j + dir[k][1];
            int ar = i + dir[k][0];
            if (ac < c && ar < r && ac >= 0 && ar >= 0 and
                word[idx + 1] == board[ar][ac]) {
                dfs(board, word, ac, ar, c, r, idx + 1);
                if (f)
                    return;
            }
        }
        board[i][j] = backup;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        int c = board[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (word[0] == board[i][j])
                    dfs(board, word, j, i, board[0].size(), board.size(), 0);
                if (f)
                    return f;
            }
        }
        return f;
    }
    int main(){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> board(n, vector<char>(m));
        for(auto &s:board)
        for(char &x:s) cin>>x;
        string s;
        cin>>s;
       cout<<exist(board,s);

    }

