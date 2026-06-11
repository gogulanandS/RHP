#include<iostream>
#include <unordered_map>
using namespace std;
int main() {
	string s;
	cin>>s;
	int n=s.length(),sum=0,maxi=0;
	unordered_map<int,int> map= {{0,-1}};
	for(int i=0; i<n; i++) {
		sum+=s[i]=='0'?-1:1;
		if(map.count(sum)) maxi=max(maxi,i-map[sum]);
		else map[sum]=i;
	}
	cout<<maxi;
}
