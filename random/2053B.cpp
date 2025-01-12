#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
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
		ll n;
		cin>>n;
		vector<ll> a(n,0), b(n,0);
		vector<ll> v;
		map<ll,ll> m;
		for(ll i=0;i<n;++i){
			cin>>a[i]>>b[i];
		}
		for(ll i=0;i<n;++i){
			if(a[i]==b[i]){
				if(!m[a[i]]){
					v.push_back(a[i]);
					++m[a[i]];
				}else{
					++m[a[i]];
				}
			}
		}
		sort(v.begin(),v.end());
		ll vs=v.size();
		vector<ll> ans;
		for(ll i=0;i<n;++i){
			ll l_num=a[i];
			ll r_num=b[i];
			// cout<<l_num<<" "<<r_num<<" "<<m[r_num]<<endl;
			if(l_num==r_num){
				if(m[l_num]>=2){
					ans.push_back(0);
				}else{
					ans.push_back(1);
				}
				continue;
			}
			ll fst_idx=2023101800;
			ll L=0, R=vs-1;
			while(L<=R){
				ll mid=(L+R)/2;
				if(v[mid]>=l_num){
					if(v[mid]<=r_num){
						fst_idx=min(fst_idx,mid);
					}
					
					R=mid-1;
				}else{
					L=mid+1;
				}
			}

			ll sed_idx=-2023101800;
			L=0, R=vs-1;
			while(L<=R){
				ll mid=(L+R)/2;
				if(v[mid]<=r_num){
					if(v[mid]>=l_num){
						sed_idx=max(sed_idx,mid);
					}
					L=mid+1;
				}else{
					R=mid-1;
				}
			}
			if(fst_idx==2023101800 || sed_idx==-2023101800){
				ans.push_back(1);
			}else{
				if(r_num-l_num==sed_idx-fst_idx){
					ans.push_back(0);
				}else{
					ans.push_back(1);
				}
			}
		}
		for(ll i=0;i<n;++i){
			cout<<ans[i];
		}cout<<"\n";
	}
	return 0;
}