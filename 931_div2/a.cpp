#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
		int N=0;
		cin>>N;
		vector<int> v;
		for(int i=0;i<N;++i){
			int a=0;
			cin>>a;
			v.push_back(a);
		}
		sort(v.begin(),v.end());
		int ans=0;
		for(int j=1;j<N-1;++j){
			for(int k=1;k<N-1;++k){
				if(j==k) continue;
				ans=max(ans,abs(v[0]-v[j])+abs(v[j]-v[k])+abs(v[k]-v[N-1])+abs(v[N-1]-v[0]));
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}