#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For std::max

using namespace std;

int main() {
    string s1, s2;
    // Using getline to match Java's sc.nextLine() behavior
    if (!getline(cin, s1) || !getline(cin, s2)) {
        return 0;
    }

    // Using vector for dynamic 2D array allocation matching sizes + 1
    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));

    // Base cases (Explicitly matching your Java initialization logic)
    for (size_t i = 0; i <= s1.length(); i++) dp[i][0] = 0;
    for (size_t j = 0; j <= s2.length(); j++) dp[0][j] = 0;

    // Fill the DP table
    for (size_t i = 1; i <= s1.length(); i++) {
        for (size_t j = 1; j <= s2.length(); j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Backtracking to find the actual subsequence string
    string result = "";
    int i = s1.length();
    int j = s2.length();
    
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            result = s1[i - 1] + result;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    cout << result << endl;

    return 0;
}
