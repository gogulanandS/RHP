#include <iostream>
#include<vector>
using namespace std;
pair<int, int> findFirstSecondIdx(const vector<int>& arr) {
	int firstIdx = (arr[0] >= arr[1]) ? 0 : 1;
	int secondIdx = (arr[0] >= arr[1]) ? 1 : 0;
	for (int i = 1; i < arr.size(); ++i) {
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
	int n,m,maxi=-1;
	cin>>n>>m;
	vector<vector<int>> arr(n,vector<int>(m, 0)),dp(n,vector<int>(m, 0));
	for(auto &a:arr)
		for(int &x:a) cin>>x;
	dp=arr;
	auto maxpair=findFirstSecondIdx(arr[0]);
	int first=maxpair.first,second=maxpair.second;
	for(int i=1; i<n; i++) {
		for(int j=0; j<m; j++) {
			dp[i][j] += (j != first) ? dp[i-1][first] : dp[i-1][second];
		}
		maxpair=findFirstSecondIdx(dp[i]);
		first=maxpair.first;
		second=maxpair.second;
	}
	for(int i=0; i<m; i++) {
		maxi=max(maxi,dp[n-1][i]);
	}
	cout<<maxi;
	return 0;
}