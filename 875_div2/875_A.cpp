#include <iostream>
#include <vector>
using namespace std;

//1013
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int n=0;
		cin>>n;
		vector<int> v;
		for(int i=1;i<=n;++i){
			int a=0;
			cin>>a;
			v.push_back(a);
		}
		for(int i=0;i<n;++i){
			cout<<n-v[i]+1<<" ";
		}
		cout<<"\n";
	}
	return 0;
}