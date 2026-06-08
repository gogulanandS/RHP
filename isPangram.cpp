#include<iostream>
using namespace std;
int main() {
	unsigned long flag=0;
	string s;
	cin>>s;
	if(s.length()<52) {
		cout<<"NO";
		return 0;
	}
	for(char ch:s) {
		if(islower(ch))  flag=flag|(long)1<<(ch-'a');
		else flag=flag|(long)1<<(ch-'A'+26);
	}
	flag==((long)1<<52)-1? cout<<"Yes":cout<<"NO";
}