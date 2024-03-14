#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int ans=0;
		vector<int> v;
		for(int i=0;i<n;++i){
			int a=0;
			cin>>a;
			v.push_back(a);
		}
		for(int i=0;i<m;++i){
			int a=0;
			cin>>a;
			for(int j=0;j<n;++j){
				if(a+v[j]<=k) ++ans;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}