#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class segmentTree {
	vector<int> Tree;
	size_t size,capacity=1;
public:
	segmentTree(vector<int>& arr) {
		size=arr.size();
		while(capacity<size) {
			capacity*=2;
		}
		Tree.resize(2*capacity,INT_MAX);
		for(size_t i=0; i<size; i++) {
			Tree[i+capacity]=arr[i];
		}
		for(size_t i = capacity;i>1;) {
             i--;
			Tree[i]=min(Tree[i*2],Tree[i*2+1]);
		}
	}
	int find(size_t Treeindex,size_t left,size_t right,size_t ql,size_t qr) {
		if(qr<left or ql>right) return INT_MAX;
		if(ql <= left && right <= qr) return Tree[Treeindex];
		size_t mid=(right-left)/2+left;
		int leftbranch=find(Treeindex*2,left,mid,ql,qr);
		int rightbranch=find(Treeindex*2+1,mid+1,right,ql,qr);
		return min(leftbranch,rightbranch);
	}
	int findval(size_t ql,size_t qr) {
		return find(1,0,capacity-1,ql,qr);
	}
};
int main() {
	int n,m;
	cin>>n>>m;
	vector<int> arr(n);
	for(int &x:arr) cin>>x;
	auto tree=segmentTree(arr);
	for(int i=0; i<m; i++) {
		size_t q1,q2;
		cin>>q1>>q2;
		cout<<tree.findval(q1-1,q2-1)<<endl;
	}
   
	return 0;
}

