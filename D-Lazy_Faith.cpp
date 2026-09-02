#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int a,b,Q;
    cin>>a>>b>>Q;
    vector<long long> s(a),t(b);
    for (auto &x:s) cin>>x;
    for (auto &x:t) cin>>x;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    while (Q--) {
        long long x,ans = 1e18;
        cin>>x;
        auto sr=lower_bound(s.begin(),s.end(),x);
        auto sl=sr!=s.begin()?prev(sr):sr;
        auto tr=lower_bound(t.begin(),t.end(),x);
        auto tl=tr!=t.begin()?prev(tr):tr;
        // right s and right t
        if (tr != t.end() && sr != s.end()) {
            long long curr = max(*tr - x, *sr - x);
            ans = min(ans, curr);
        }
        // 2. Left s and left t
        if (sr != s.begin() && tr != t.begin()) {
            long long curr = max(x - *tl, x - *sl);
            ans = min(ans, curr);
        }
        // 3. Left t and right s
        if (sr != s.end() && tr != t.begin()) {
            long long curr = min(x - *tl + (*sr - *tl), *sr - x + (*sr - *tl));
            ans = min(ans, curr);
        }
        // 4. Left s and right t
        if (sr != s.begin() && tr != t.end()) {
            long long curr = min(x - *sl + (*tr - *sl), *tr - x + (*tr - *sl));
            ans = min(ans, curr);
        }
        cout<<ans<<endl;
    }
    return 0;
}