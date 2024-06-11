#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
ll lcm(ll a, ll b){
	return (a*b)/gcd(a,b);
}
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		ll cur_lcm=1;
		ll a=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			cur_lcm=lcm(max(cur_lcm,v[i]),min(cur_lcm,v[i]));
		}
		// for(ll i=0;i<n;++i){
		// 	a+=cur_lcm/v[i];
		// 	cout<<a<<endl;

		// }
		// cout<<cur_lcm<<endl;
		ll L=1;
		ll R=1000000000;
		bool flag=0;
		ll ans=0;
		while(L<=R){
			ll mid=(L+R)/2;
			// sum이 mid임
			ll cur_sum=cur_lcm*mid;
			for(ll i=0;i<n;++i){
				cur_sum-=(cur_lcm/v[i])*mid;
			}
			if(cur_sum<n*cur_lcm){
				L=mid+1;
			}else if(cur_sum>=n*cur_lcm){
				R=mid-1;
				flag=1;
				ans=mid;
				// cout<<ans<<endl;
				break;
			}
		}
		if(flag){
			vector<ll> res;
			for(ll i=0;i<n;++i){
				res.push_back(ans/v[i]+1);
			}
			for(ll i=0;i<n;++i){
				cout<<res[i]<<" ";
			}cout<<"\n";
		}else{
			cout<<-1<<"\n";
		}
		
	} 
	return 0;
}