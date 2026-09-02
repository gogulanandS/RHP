#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    vector<int> r_b(h, 0), c_b(w, 0), d(h * w, -1);
    queue<int> q;

    for (int i = 0; i < h; ++i) {
        cin >> s[i];
        for (int j = 0; j < w; ++j) 
            if (s[i][j] == '#') r_b[i] = c_b[j] = 1;
    }

    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            if (s[i][j] == '.' && !r_b[i] && !c_b[j]) {
                d[i * w + j] = 0;
                q.push(i * w + j);
            }

    int ans = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        int r = u / w, c = u % w;
        if (d[u] <= k) ans++;

        for (int i = 0; i < 4; ++i) {
            int nr = r + (int[]){-1, 1, 0, 0}[i];
            int nc = c + (int[]){0, 0, -1, 1}[i];
            int v = nr * w + nc;
            if (nr >= 0 && nr < h && nc >= 0 && nc < w && s[nr][nc] == '.' && d[v] == -1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    cout << ans << "\n";
}
