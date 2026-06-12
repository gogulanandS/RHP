#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s1, s2;
    // Using getline to match Java's sc.nextLine() behavior
    if (!getline(cin, s1) || !getline(cin, s2)) {
        return 0;
    }

    int flag[2] = {0, 0}; // flag[0] stores max length, flag[1] stores ending index in s1
    
    // Using vector for dynamic 2D array allocation matching s1 and s2 sizes
    vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), 0));

    for (int i = 0; i < s1.length(); i++) {
        for (int j = 0; j < s2.length(); j++) {
            if (s1[i] == s2[j]) {
                dp[i][j] = (i > 0 && j > 0) ? dp[i - 1][j - 1] + 1 : 1;
                
                if (dp[i][j] > flag[0]) {
                    flag[0] = dp[i][j];
                    flag[1] = i;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    string result = "";
    for (int i = flag[1] - flag[0] + 1; i <= flag[1]; i++) {
        result += s1[i];
    }

    cout << result << endl;

    return 0;
}
