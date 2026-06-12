#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<int> rice(n),toping(m);
  for(int &x:rice) cin>>x;
  for(int &x:toping) cin>>x;
  sort(rice.begin(),rice.end());
  sort(toping.begin(),toping.end());
  int i=0,j=0,count=0;
  while(i<n and j<m){
    if(toping[j] <= 2 * rice[i]){
      i++;
      j++;
      count++;
    }
    else{
      i++;
    }
  }
 cout<<count;
}