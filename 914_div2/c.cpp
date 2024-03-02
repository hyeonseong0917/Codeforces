#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
 
#define ll long long
 
 
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=0;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			ll a=0;
			cin>>a;
			v[i]=a;
		}
		sort(v.begin(),v.end());
 
		ll ans=v[0];
		// cout<<ans<<"\n";
		for(ll i=0;i<n-1;++i){
			ans=min(ans,(ll)abs(v[i+1]-v[i]));
		}
		if(k>=3){
			cout<<0<<"\n";
			continue;
		}else if(k==2){
			for(ll i=0;i<n;++i){
				for(ll j=0;j<i;++j){
					ll diff=v[i]-v[j];
					ll L=0;
					ll R=n-1;
					ll mid;
 
					while(L<R){
						mid=(L+R)/2;
						if(v[mid]<diff){
							L=mid+1;
						}else{
							R=mid;
						}
					}
					if(R-1>=0){
						ans=min(ans,diff-v[R-1]);	
					}
					if(R<n){
						ans=min(ans,v[R]-diff);		
					}
					
				}
			}
		}
		cout<<ans<<"\n";
 
	}	
	return 0;
}