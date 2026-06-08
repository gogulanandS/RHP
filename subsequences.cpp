#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();

    // 1 << n calculates 2^n
    for (int bit = 1; bit < (1 << n); bit++) {
        string ans = ""; // Initialize inside the loop to avoid manual clearing
        
        for (int i = 0; i < n; i++) {
            // Check if the i-th bit is set
            if ((bit & (1 << i)) != 0) {
                ans += s[i];
            }
        }
        cout << ans << " "<<bit<< endl;
    }
    return 0;
}
