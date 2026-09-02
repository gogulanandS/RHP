// Compile & Run: g++ -std=c++23 -Wall -Wextra -g D-Many_Repunit_Sum.cpp -o
// D-Many_Repunit_Sum && ./D-Many_Repunit_Sum Problem: Sum of repunits (1, 11,
// 111, ...) where count >= arr[i] for each element Algorithm: Count elements >=
// each repunit value, build sum with carry propagation

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, carry = 0;        // n: input size, carry: for digit carrying
    cin >> n;                // read number of elements
    vector<int> arr(n), ans; // arr: input array, ans: answer array
    for (int& x : arr)
        cin >> x;                 // read all array elements
    sort(arr.begin(), arr.end()); // sort in ascending order
    for (int i = 1; i <= arr[n - 1];i++) { // iterate for each repunit (1,11,111,...)
        auto it =lower_bound(arr.begin(), arr.end(), i); // find first element >= i
        int cnt = arr.end() - it;                   // count of elements >= i
        carry += cnt;                               // add to carry (sum so far)
        ans.push_back(carry % 10);                  // store last digit
        carry = carry / 10; // remove last digit for next iteration
    }
    while (carry) {                // handle remaining carry
        ans.push_back(carry % 10); // store each digit
        carry /= 10;               // move to next digit
    }
    while (!ans.empty()) {  // print answer in reverse (built bottom-up)
        cout << ans.back(); // print last digit
        ans.pop_back();     // remove it
    }
}
