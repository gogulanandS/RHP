#include <bits/stdc++.h>
using namespace std;    

    int maxRotateFunction(vector<int>& nums) {
      int n=nums.size();
      long long sum=0,diff=0,maxi=INT_MIN;
      for(int i=0;i<n;i++){
        diff+=(long long)i*nums[i];
        sum+=nums[i];
    }
    maxi=diff;
    for(int i=0;i<n-1;i++){
       diff = diff + sum - (long long)n * nums[n - 1 - i];
        maxi=max(maxi,diff);
    }
    return maxi;
    }
    
    int main() {
        int n;cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++) cin>>nums[i];
        cout<<maxRotateFunction(nums);
        return 0;
    }          
