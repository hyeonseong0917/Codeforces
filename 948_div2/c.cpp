#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long
//a>b
ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
ll lcm(ll a, ll b){
	return (a*b)/gcd(a,b);
}
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		map<ll,ll> visited;
		ll lcm_num=1;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			++visited[v[i]];
			if(lcm_num<=1000000000){
				lcm_num=lcm((ll)max(lcm_num,v[i]),(ll)min(lcm_num,v[i]));	
			}
			
			// cout<<lcm_num<<endl;
		}
		if(lcm_num>1000000000){
			cout<<n<<"\n";
			continue;
		}
		// cout<<lcm_num<<endl;
		ll ans=0;
		sort(v.begin(),v.end());
		vector<ll> d;
		for(ll i=1;i*i<=lcm_num;++i){
			if(lcm_num%i==0){
				d.push_back(i);
				if(i!=lcm_num/i){
					d.push_back(lcm_num/i);
				}
			}
		}
		sort(d.begin(),d.end());
		reverse(d.begin(),d.end());
		for(ll i=0;i<d.size();++i){
			ll cur_div=d[i];
			ll cur_lcm=1;
			ll cnt=0;
			for(ll j=n-1;j>=0;--j){
				if(v[j]>=cur_div) continue;
				if(cur_div%v[j]==0){
					++cnt;
					cur_lcm=lcm((ll)max(cur_lcm,v[j]),(ll)min(cur_lcm,v[j]));
				}
			}
			if(!visited[cur_lcm]){
				ans=max(ans,cnt);
			}
		}
		cout<<ans<<"\n";

	}	
	return 0;
}