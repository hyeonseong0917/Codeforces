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
	int t=0;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		ll ans=0;
		if(v[0]<0 && v[n-1]>0){
			// - + 둘 다 있음
			// -15 -10 -5 3 4 5 6 7 8
			vector<ll> plus_vector, minus_vector;
			for(ll i=0;i<n;++i){
				if(v[i]<0){
					minus_vector.push_back(v[i]*-1);
				}else{
					plus_vector.push_back(v[i]);
				}
			}
			sort(minus_vector.begin(),minus_vector.end());
			ll ps=plus_vector.size();
			ll ms=minus_vector.size();
			ll idx=ps-1;
			bool is_plus_big=0;
			if(plus_vector[ps-1]>minus_vector[ms-1]){
				is_plus_big=1;
			}
			while(idx>=0){
				ll cur_num=plus_vector[idx];
				ans+=plus_vector[idx]*2;
				if(idx==ps-1 && is_plus_big){
					ans-=cur_num;
				}
				idx-=(k);
			}
			// cout<<ans<<"\n";
			idx=ms-1;
			while(idx>=0){
				ll cur_num=minus_vector[idx];
				ans+=minus_vector[idx]*2;
				if(idx==ms-1 && !is_plus_big){
					ans-=cur_num;
				}
				idx-=(k);
			}
		}else{
			// 부호 하나만 있음
			for(ll i=0;i<n;++i){
				if(v[i]<0){
					v[i]*=-1;
				}
			}
			sort(v.begin(),v.end());
			ll idx=n-1;
			while(idx>=0){
				ll cur_num=v[idx];
				ans+=v[idx]*2;
				if(idx==n-1){
					ans-=cur_num;
				}
				idx-=(k);
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
}