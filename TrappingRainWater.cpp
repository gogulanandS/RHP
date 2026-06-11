#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[n], maxi = 0, mini, sum = 0;
    for (int& x : arr)
        cin >> x;
    int LargeLeft[n], Largeright[n];
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, arr[i]);
        LargeLeft[i] = maxi;
    }
    maxi = 0;
    for (int i = n - 1; i >= 0; i--) {
        maxi = max(arr[i], maxi);
        Largeright[i] = maxi;
    }
    for (int i = 0; i < n; i++) {
        mini = min(Largeright[i], LargeLeft[i]);
        sum += mini - arr[i];
    }
    cout << sum;
}