// Compile & Run: g++ -std=c++23 -Wall -Wextra -g longestCommonSubsequence.cpp -o lcs && ./lcs
// Problem: Find length of longest common subsequence between two strings
// Algorithm: Dynamic Programming - dp[i][j] = LCS length of text1[0..i-1] and text2[0..j-1]

#include <iostream>
#include <vector>
using namespace std;
int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.length();                               // length of first string
    int m = text2.length();                               // length of second string
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // DP table (n+1)x(m+1) initialized to 0

    for (int i = 1; i <= text1.length(); i++)
    { // iterate through first string
        for (int j = 1; j <= text2.length(); j++)
        { // iterate through second string
            if (text1[i - 1] == text2[j - 1])
            {                                    // if characters match
                dp[i][j] = dp[i - 1][j - 1] + 1; // extend LCS by 1
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // take max from left or top
        }
    }
    return dp[text1.length()][text2.length()]; // return LCS length
}
int main()
{
    string text1, text2;                            // declare two strings
    cin >> text1 >> text2;                          // read both strings
    cout << longestCommonSubsequence(text1, text2); // print LCS length
}