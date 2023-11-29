#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
	// your code goe1s here
	int t=0;
	cin>>t;
	while(t--){
		int n,x;
		vector<int> v;
		cin>>n>>x;
		int max_diff=-1;
		for(int i=0;i<n;++i){
			int a=0;
			cin>>a;
			v.push_back(a);
		}
		sort(v.begin(),v.end());
		max_diff=max(max_diff,v[0]);
		for(int i=1;i<n;++i){
			max_diff=max(max_diff,v[i]-v[i-1]);	
		}
		max_diff=max(max_diff,(x-v[n-1])*2);
		cout<<max_diff<<"\n";
	}
	return 0;
}