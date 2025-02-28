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
		ll n,m,d;
		cin>>n>>m>>d;
		vector<ll> p(n+1,0), a(m+1,0);
		vector<ll> pos(n+1,0);
		for(ll i=0;i<n;++i){
			cin>>p[i];
			pos[p[i]]=i;
		}
		for(ll i=0;i<m;++i){
			cin>>a[i];
		}
		ll ans=2023101800;
		for(ll i=0;i<m-1;++i){
			if(pos[a[i]]>=pos[a[i+1]] || pos[a[i+1]]>pos[a[i]]+d){
				ans=0;
				break;
			}
			ll fst_diff=pos[a[i+1]]-pos[a[i]];
			ll sed_diff=d+1-(pos[a[i+1]]-pos[a[i]]);
			ll cnt=pos[a[i]]+n-1-pos[a[i+1]];
			if(cnt>=sed_diff){
				ans=min(ans,min(fst_diff,sed_diff));
			}else{
				ans=min(ans,fst_diff);
			}
			
		}
		cout<<ans<<"\n";
	} 
	return 0;
}