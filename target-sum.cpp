#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int count = 0;

    void solve(vector<int>& nums, int sum, int index, int target, int n) {
        if (index == n) {
            if (sum == target) count++;
            return;
        }
        solve(nums, sum + nums[index], index + 1, target, n);
        solve(nums, sum - nums[index], index + 1, target, n);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        count = 0; // Essential reset so multiple test runs don't mess up the count
        solve(nums, 0, 0, target, nums.size());
        return count;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "Array cannot be empty." << endl;
        return 0;
    }

    vector<int> nums(n);
    cout << "Enter " << n << " array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter the target sum value: ";
    cin >> target;

    Solution sol;
    int combinations = sol.findTargetSumWays(nums, target);

    cout << "\nTotal number of ways to assign signs to reach target: " << combinations << endl;

    return 0;
}
