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
	ll t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> tmp;
		ll max_odd_num=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			if(v[i]%2==1){
				max_odd_num=max(max_odd_num,v[i]);
			}else{
				tmp.push_back(v[i]);
			}
		}
		sort(v.begin(),v.end());
		// 모두 홀수인지?
		bool is_all_odd=1;
		for(ll i=0;i<n;++i){
			if(v[i]%2==0){
				is_all_odd=0;
				break;
			}
		}
		bool is_all_even=1;
		for(ll i=0;i<n;++i){
			if(v[i]%2==1){
				is_all_even=0;
				break;
			}
		}
		if(is_all_even || is_all_odd){
			cout<<0<<"\n";
			continue;
		}
		ll ans=0;
		sort(tmp.begin(),tmp.end());
		ll ts=tmp.size();
		ll L=0, R=ts-1;
		while(L<=R){
			if(tmp[L]<max_odd_num){
				max_odd_num+=tmp[L];
				++ans;
				++L;
			}else{
				max_odd_num=max_odd_num+tmp[R]*2;
				ans+=2;
				--R;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}