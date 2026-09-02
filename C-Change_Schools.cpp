#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, m = 0, ans = 0;
    cin >> n >> k;
    vector<int> c(k + 1);
    for (int i = 0, a; i < n; i++) cin >> a, m = max(m, ++c[a]);
    for (int i = 1; i <= k; i++) ans += (c[i] >= m - 1);
    cout << ans;
}
