#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> H(N);
    vector<int> L(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i] >> L[i];
    }

    // Suffix Maximum
    vector<int> suffixMax(N);
    suffixMax[N - 1] = H[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        suffixMax[i] = max(H[i], suffixMax[i + 1]);
    }

    int Q;
    if (!(cin >> Q)) return 0;

    while (Q-- > 0) {
        int T;
        cin >> T;

        int left = 0;
        int right = N - 1;
        int ans = N;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (L[mid] > T) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        cout << suffixMax[ans] << "\n";
    }

    return 0;
}
