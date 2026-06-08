#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> findFirstSecondIdx(vector<int> &arr) {
	if (arr.size() < 2) return {0, 0};

	int firstIdx = (arr[0] >= arr[1]) ? 0 : 1;
	int secondIdx = (arr[0] >= arr[1]) ? 1 : 0;
	for (int i = 2; i < arr.size(); ++i) {
		if (arr[i] >= arr[firstIdx]) {
			secondIdx = firstIdx;
			firstIdx = i;
		}
		else if (arr[i] > arr[secondIdx]) {
			secondIdx = i;
		}
	}
	return {firstIdx, secondIdx};
}
int main()
{
	int n, m, maxi = -1;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m, 0)), dp(n, vector<int>(m, 0));
	for(auto &a : arr)
		for(int &x : a) cin >> x;
	dp = arr;
	vector<int> Colm(n);
	for(int i = 0; i < n; i++) {
		Colm[i] = dp[i][0];
	}
	auto maxpair = findFirstSecondIdx(Colm);
	int first = maxpair.first, second = maxpair.second;
	for(int j = 1; j < m; j++) {
		for(int i = 0; i < n; i++) {
			dp[i][j] += (i != first) ? dp[first][j-1] : dp[second][j-1];
		}
		for(int i = 0; i < n; i++) {
			Colm[i] = dp[i][j];
		}
		maxpair = findFirstSecondIdx(Colm);
		first = maxpair.first;
		second = maxpair.second;
	}
    
	for(int i = 0; i < n; i++) {
		maxi = max(maxi, dp[i][m-1]);
	}
    
	cout << maxi;
	return 0;
}