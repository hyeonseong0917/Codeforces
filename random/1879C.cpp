#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long
ll mod=998244353;
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		ll n=s.size();

		ll idx=0;
		vector<ll> v;
		while(idx<n){
			if(idx<n-1 && s[idx]==s[idx+1]){
				ll cnt=0;
				ll tmp_idx=idx;
				// cout<<tmp_idx<<endl;
				for(ll i=tmp_idx;i<n;++i){
					if(s[i]==s[tmp_idx]){
						++cnt;
						++idx;
					}else{
						break;
					}
				}
				v.push_back(cnt);
			}else{
				++idx;
				v.push_back(1);
			}
		}
		// cout<<v[0]<<endl;
		ll ans=1;
		ll fst_num=0;
		for(ll i=0;i<v.size();++i){
			fst_num+=v[i]-1;
		}
		ll fact=1;
		for(ll i=1;i<=fst_num;++i){
			fact*=i;
			fact%=mod;
		}
		ans*=fact;
		for(ll i=0;i<v.size();++i){
			ans*=(v[i])%mod;
			ans%=mod;
		}

		cout<<fst_num<<" "<<ans<<"\n";

	} 
	return 0;
}