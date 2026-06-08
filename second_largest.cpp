#include <iostream>
#include <climits>
#include <vector>
using namespace std;

pair<int, int> getLargestAndSecondLargest(const vector<int>& arr) {
    int n = arr.size();
    if (n < 2) {
        return {-1, -1};
    }
    int large = INT_MIN;
    int second_large = INT_MIN;
    bool issecond_large = false; // Tracks if second_large ever changed

    for (int i = 0; i < n; i++) {
        if (arr[i] > large) {
            if (i > 0) { 
                second_large = large;
                issecond_large = true;
            }
            large = arr[i];
        } 
        else if (arr[i] > second_large and arr[i] != large) {
            second_large = arr[i];
            issecond_large = true;
        }
    }
    if (!issecond_large) {
        second_large = large; 
    }
    return {large, second_large};
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr) {
        cin >> x;
    }
    auto result = getLargestAndSecondLargest(arr);
    cout << "Largest element: " << result.first << endl;
    cout << "Second largest element: " << result.second << endl;
    return 0;
}
