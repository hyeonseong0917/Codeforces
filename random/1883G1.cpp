#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		// m==1
		ll n,m;
		cin>>n>>m;
		vector<ll> a(n,0), b(n,0);
		for(ll i=1;i<n;++i){
			cin>>a[i];
		}
		for(ll i=0;i<n;++i){
			cin>>b[i];
		}
		a[0]=1;
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		ll L=0, R=n;
		ll ans=R;
		while(L<=R){
			ll mid=(L+R)/2;
			ll fst_idx=0;
			ll sed_idx=mid;
			bool flag=0;
			while(fst_idx<=n-mid-1){
				if(a[fst_idx]<b[sed_idx]){
					++fst_idx;
					++sed_idx;
					continue;
				}
				flag=1;
				break;
			}
			if(flag){
				L=mid+1;
			}else{
				ans=min(ans,mid);
				R=mid-1;
			}
		}
		cout<<ans<<"\n";

	} 
	return 0;
}