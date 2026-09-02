#include <iostream>
#include<vector>
#include<algorithm>
#include <typeinfo>
using namespace std;

static int counter=0;
static int cmp(const string &a, const string &b) {
    counter++;
    return a + b > b + a;
}

static string largestNumber(const vector<int>& nums) {
        vector<string> v;
        v.reserve(nums.size());
        for(const int x:nums)
            v.push_back(to_string(x));
        
       sort(v.begin(), v.end(), cmp); 
       
         size_t totalLen = 0;
        for (const string& s : v)
            totalLen += s.size();

        string ans;
        ans.reserve(totalLen);
        for(const string &x:v)ans+=x;
       cout<< typeid(v).name()<<endl;
        return ans;
    }
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &x: nums) cin >> x;
    cout << largestNumber(nums) << endl<<counter<<endl;
}
