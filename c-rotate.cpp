#include <iostream>
#include <string>
#include<print>
using namespace std;
int main() {
    int n, q;
    cin >> n >> q;
    
    string s;
    cin >> s;

    int pos = 0; // Start at the beginning of the string

    while (q--) {
        int t, x;
        cin >> t >> x;

        if (t == 1) {
            // Shift pos backward by x steps
            pos = (pos - x) % n;
            if (pos < 0) {
                pos += n;
            }
        } else {
            // Convert 1-based index x to 0-based index (x - 1)
            cout << s[(pos + x - 1) % n] << endl;
        }
    }

    return 0;
}
