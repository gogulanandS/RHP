#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper function to add two large numeric strings safely without integer overflow
    string stringAdd(const string& num1, const string& num2) {
        string res = "";
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';
            res += to_string(sum % 10);
            carry = sum / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }

public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for (int flen = 1; flen <= n / 2; flen++) {
            if (num[0] == '0' && flen > 1) break;
            
            for (int slen = 1; n - (flen + slen) >= max(flen, slen); slen++) {
                if (num[flen] == '0' && slen > 1) break;
                
                string fnum = num.substr(0, flen);
                string snum = num.substr(flen, slen);
                string bal = num.substr(flen + slen);
                
                while (!bal.empty()) {
                    string tstring = stringAdd(fnum, snum);
                    
                    // Check if the remaining string starts with our expected sum sequence
                    if (bal.find(tstring) == 0) {
                        fnum = snum;
                        snum = tstring;
                        bal = bal.substr(tstring.size());
                    } else {
                        break;
                    }
                }
                
                if (bal.empty()) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    string num;
    cout << "Enter a numeric sequence string: ";
    cin >> num;

    Solution sol;
    bool result = sol.isAdditiveNumber(num);

    if (result) {
        cout << "\nResult: True (It is a valid Additive Number)" << endl;
    } else {
        cout << "\nResult: False (It is NOT a valid Additive Number)" << endl;
    }

    return 0;
}
