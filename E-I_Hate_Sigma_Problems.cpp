#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Optimize standard I/O operations for speed
/*https://www.google.com/search?q=E-I_Hate_Sigma_Problems&gs_lcrp=EgZjaHJvbWUyBggAEEUYOTIICAEQABgNGB4yDQgCEAAYhgMYgAQYigXSAQgxNjE2ajBqN6gCALACAA&sourceid=chrome&ie=UTF-8&udm=50&fbs=ABfTbFVyMZGZf1hfvX9uKjN_-G8cqu7ocb7U6ah0xpkIrGMK4LpKPoHZrc4HVz9uOAATjT2YNhIfH8_EI3sjv29QUM5ncLocu7BDRIjT4DA77V3-npMVRsIYI67GHAEqhhmRaJH5zBmyMIpjtxY1nn8MceEl6V14L6-QwaLKPXKdnXdrucrCOJbWN_figz6IxBX3KvgRfkvkyAEq24OQQryNVNAzwmvf3Q&aep=10&ntc=1&mstk=AUtExfBLS9pouKI88-2zRNIqbq2ypxHkKFKOQB85VyuP8_Kby1IuoGbUF88dJETUhhwKLzhIwa2NTUL2IHhDe-KAcsGLGg2dwE1cRvC2uKczgZiftTD_KjKEV6PPlRnijBBwPmkVStzUS6RFf-DAdLDvC4RJk2GUrYPz9O4XKq_m3OcnPKEiPfTu4DvXvxqZQ8VeuOafahboYakvPyX2-p83KYKEbRGDNfoRQLzEVy9P2a-nTdYz9rMHLeNM1sQIfeax4sNFWaCAZxhZfw&aioh=3&csuir=1&cs=1&atvm=2&mtid=OmZ0auaHELaUhvcPn4iC0QE&lns_mode=cvst&elids=CMjPtqXb1q22uAEQARgBIhAR_JSpBwjMTwPtKxK1BjXxMoIBIgJ0cCg9QnQKLmxmZS1kdW1teTozYzkyNTY3OC1jYmIyLTQ4ODQtYmNkYi03N2YxNTFhOWM3MjYSQgpAL2Jucy90cC9ib3JnL3RwL2Jucy9sZW5zLWZyb250ZW5kLWFwaS9wcm9kLmxlbnMtZnJvbnRlbmQtYXBpLzM0MloECgJ0cDjgmYGf6ouWA1AAaglpbWFnZS9wbmc%2CCOD90Obt19GGlwEQARgBIhD24JHl7jEGLMD1M6rioW1BMoIBIgJ0cChkQnQKLmxmZS1kdW1teToyMWEyNTU4Ni0xM2I4LTQ2YjctYjE0OS02ODViZmVlYmJmNjkSQgpAL2Jucy90cC9ib3JnL3RwL2Jucy9sZW5zLWZyb250ZW5kLWFwaS9wcm9kLmxlbnMtZnJvbnRlbmQtYXBpLzE0MloECgJ0cDjY1JTv6ouWA1AAaglpbWFnZS9wbmc
*/

    int n;
    if (!(cin >> n)) return 0;

    vector<int> arr(n);
    for (int &x : arr) {
        cin >> x;
    }

    // prev[v] will store the NEXT (rightmost) occurrence index of value v.
    // Since elements can be up to N, size N + 1 is safe. Initialize all to N.
    vector<int> prev(n + 1, n);

    long long sum = 0;
    long long last = 0;
    for (int i = n - 1; i >= 0; i--) {
        int next_occurrence = prev[arr[i]];

        // arr[i] contributes 1 extra unique element to all subarrays
        // starting at i and ending before its next occurrence.
        last += (next_occurrence - i);

        sum += last;

        // Update the next occurrence tracker for this value
        prev[arr[i]] = i;
    }

    cout << sum << "\n";

    return 0;
}
