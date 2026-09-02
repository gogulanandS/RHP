#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size(), j = 0, k = n - 1;
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n - 2; i++) {
            j = i + 1;
            k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while (j < k and nums[j] == nums[j + 1]) {
                        j++;
                    }
                    while (j < k and nums[k] == nums[k - 1]) {
                        k--;
                    }
                    j++;
                    k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
            while (i < n - 2 and nums[i] == nums[i + 1]) i++;
        }
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    if (n < 3) {
        cout << "You need at least 3 numbers to find triplets!" << endl;
        return 0;
    }

    vector<int> nums(n);
    cout << "Enter " << n << " numbers separated by spaces: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    vector<vector<int>> result = sol.threeSum(nums);
    
    if (result.empty()) {
        cout << "No triplets found that sum to zero." << endl;
    } else {
        cout << "\nTriplets that sum to zero are:\n";
        for (const auto& triplet : result) {
            cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]\n";
        }
    }
    
    return 0;
}
