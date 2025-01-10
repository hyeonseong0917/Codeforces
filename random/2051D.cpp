#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	ll t=1;
	cin>>t;
	while(t--){
		ll n,x,y;
		cin>>n>>x>>y;
		vector<ll> v(n,0);
		ll psum=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			psum+=v[i];
		}
		sort(v.begin(),v.end());
		ll L=0, R=n-1;
		ll ans=0;
		while(L<R){
			if(x<=psum-v[R]-v[L] && psum-v[R]-v[L]<=y){
				// 최소의 idx 찾기
				ll left=L+1;
				ll right=R-1;
				ll m=2023101800;
				while(left<=right){
					ll mid=(left+right)/2;
					if(psum-v[mid]-v[L]>=x && psum-v[mid]-v[L]<=y){
						m=min(m,mid);
						right=mid-1;
					}else{
						if(psum-v[mid]-v[L]<x){
							right=mid-1;
						}else{
							left=mid+1;
						}
						// left=mid+1;
					}
				}
				// cout<<L<<" "<<R<<" "<<m<<endl;
				if(m!=2023101800){
					ans+=(R-m+1);
				}else{
					ans+=1;
				}
				++L;
			}else{
				if(psum-v[R]-v[L]<x){
					--R;
				}else{
					++L;
				}
				// --R;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}