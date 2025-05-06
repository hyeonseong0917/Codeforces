#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		ll idx=-1;
		for(ll i=0;i<n;++i){
			if(v[i]>0){
				idx=i;
				break;
			}
		}
		if(idx==-1){
			cout<<n<<"\n";
			continue;
		}
		bool flag=0;
		for(ll i=1;i<=idx;++i){
			if(abs(v[i]-v[i-1])<v[idx]){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<max(idx,1ll)<<"\n";
		}else{
			cout<<max(idx+1,1ll)<<"\n";
		}
		
	} 
	return 0;
}