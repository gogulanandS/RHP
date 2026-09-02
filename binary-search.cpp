#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1; // Edge case safety
        
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (target > nums[mid]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        
        // When loop ends, l == r
        return (nums[l] == target) ? l : -1;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements in the sorted array: ";
    cin >> n;

    if (n <= 0) {
        cout << "Array cannot be empty." << endl;
        return 0;
    }

    vector<int> nums(n);
    cout << "Enter " << n << " sorted numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter the target number to find: ";
    cin >> target;

    Solution sol;
    int index = sol.search(nums, target);

    if (index != -1) {
        cout << "Target found at index: " << index << endl;
    } else {
        cout << "Target not found in the array (-1)." << endl;
    }

    return 0;
}
