#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    long long k; // K can be large, use long long to prevent overflow
    if (!(cin >> n >> m >> k)) return 0;

    vector<int> v(n);
    long long sum = 0; // Tracks calories consumed in the current M-day window

    for (int i = 0; i < n; i++) {
        cin >> v[i]; // Read input directly in the main loop

        // 1. Sliding window step: Slide out the day that is now older than M days
        if (i >= m) {
            sum -= v[i - m];
        }

        // 2. Evaluation step: Check if adding the new snack exceeds the limit K
        if (sum + v[i] <= k) {
            sum += v[i];   // Add to the sliding window sum
            cout << "Yes\n";
        } else {
            v[i] = 0;      // Important: He skips this snack, so it contributes 0 calories
            cout << "No\n";
        }
    }

    return 0;
}
