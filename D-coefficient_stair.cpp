#include <iostream>
#include <vector>
using namespace std;

int N, K;
void dfs(int i, int rem, vector<int>& v) {
    if (i == N) {
        if (rem % N == 0) {
            for (int x : v) cout << x << " ";
            cout << rem / N << "\n";
        }
        return;
    }
    for (int a = 0; i * a <= rem; ++a) {
        v.push_back(a);
        dfs(i + 1, rem - i * a, v);
        v.pop_back();
    }
}
int main() {
    if (cin >> N >> K) { vector<int> v; dfs(1, K, v); }
}
