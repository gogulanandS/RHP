#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> v(3*n+1,0);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v[x]++;
        }
        int ans=0;
        for(int i=1;i<=2*n;i++){
            int cur=i;
            while(v[cur]>k){
                v[cur+1]+=v[cur]-1;
                v[cur]=1;
                cur++;
            }
            ans=max(ans,cur-i);
            i=cur;
        }
        cout<<ans<<endl;
    }
}