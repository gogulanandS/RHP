#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        // If lengths don't match, s can never be rotated into goal
        if (s.length() != goal.length()) {
            return false;
        }
        
        // Concatenate s with itself to capture all possible rotations
        string doubled_s = s + s;
        
        // Safe cross-version check: returns true if goal is found inside doubled_s
        return doubled_s.find(goal) != string::npos;
    }
};

int main() {
    string s, goal;
    
    cout << "Enter the original string (s): ";
    cin >> s;
    
    cout << "Enter the target string (goal): ";
    cin >> goal;

    Solution sol;
    bool result = sol.rotateString(s, goal);

    if (result) {
        cout << "\nResult: True (\"" << goal << "\" is a valid rotation of \"" << s << "\")" << endl;
    } else {
        cout << "\nResult: False (\"" << goal << "\" is NOT a rotation of \"" << s << "\")" << endl;
    }

    return 0;
}
