
#include <iostream>
#include <vector>
using namespace std;

static int find(vector<int>& arr, int node) {
    if (arr[node] != node) {
        arr[node] = find(arr, arr[node]);
    }
    return arr[node];
}

static void join(vector<int>& arr, int st, int end) {
    const int lt = find(arr, st);
    int rt = find(arr, end);
    if(lt!=rt)
    arr[lt] = rt;
}
 int main() {
    int n, m;
    long long sum=0;
     if (!(cin >> n >> m)) return 0;
    vector<int> arr(n + 1), groupcnt(n + 1, 0), edgecnt(n + 1, 0), start(m);
    for (int i = 0; i <= n; i++)
        arr[i] = i;
    for (int i = 0; i < m; i++) {
        int st, end;
        cin >> st >> end;
        start[i] = st;
        join(arr, st, end);
    }
    for (int i = 1; i <= n; i++) {
         groupcnt[find(arr, i)]++;
    }
    for (int i = 0; i < m; i++) {
        edgecnt[find(arr, start[i])]++;
    }
for(int i=1;i<=n;i++)
    {
         if (find(arr, i) == i) { 
        int ncnt=groupcnt[i];
        sum+=((1LL*ncnt*(ncnt-1))/2)-edgecnt[i];
         }
    }
cout<<sum;
    return 0;
}