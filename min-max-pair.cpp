#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	cin>>n;
	vector<int> v(n + 1);
	for (int x = 1; x <= n; x++) cin >> v[x];
	long same=0,exchange = 0;
	for (int i = 1; i <= n; i++) {
		if (v[i] == i) {
			same++;
		} else if ( v[v[i]] == i) {
			exchange++;
		}
	}
	cout << same * (same - 1) / 2 + exchange/2<< "\n";
	return 0;
}
