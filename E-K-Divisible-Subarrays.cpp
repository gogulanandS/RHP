#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main() {
    // Optimize standard I/O operations for performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    if (!(std::cin >> n >> k)) return 0;

    int rem = 0;
    std::unordered_map<int, int> m;
    std::vector<int> arr(n + 1, 0);
    
    m[0] = 0;

    for (int i = 1; i <= n; i++) {
        int c;
        std::cin >> c;
        
        // Handles standard and negative remainder math correctly
        rem = (rem + c) % k;
        if (rem < 0) rem += k; 

        arr[i] = arr[i - 1];

        if (m.find(rem) != m.end()) {
            int prev = m[rem];
            arr[i] = std::max(arr[i - 1], 1 + arr[prev]);
        }
        m[rem] = i;
    }

    std::cout << arr[n] << "\n";

    return 0;
}
