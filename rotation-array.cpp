#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return; // Added an empty array safety check
        
        k = k % n;
        if (n == 1 || k == 0) return;
        
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "Array size must be greater than 0." << endl;
        return 0;
    }

    vector<int> nums(n);
    cout << "Enter " << n << " array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cout << "Enter the number of steps to rotate (k): ";
    cin >> k;

    Solution sol;
    sol.rotate(nums, k);

    cout << "\nArray after rotating by " << k << " steps right:\n";
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << nums[i] << (i + 1 < n ? ", " : "");
    }
    cout << "]\n";

    return 0;
}
