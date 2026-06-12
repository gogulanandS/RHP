#include <iostream>
#include <vector>
using namespace std;
const int MAX_TEMP = 200005;
int main() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> diff(MAX_TEMP, 0);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        diff[l]++;
        diff[r + 1]--;
    }
    vector<int> admissible(MAX_TEMP, 0);
    int current_recipes = 0;
    for (int i = 0; i < MAX_TEMP; i++) {
        current_recipes += diff[i];
        if (current_recipes >= k) {
            admissible[i] = 1;
        } else {
            admissible[i] = 0;
        }
    }
    vector<int> pref(MAX_TEMP, 0);
    for (int i = 1; i < MAX_TEMP; i++) {
        pref[i] = pref[i - 1] + admissible[i];
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << pref[b] - pref[a - 1] << "\n";
    }

    return 0;
}
