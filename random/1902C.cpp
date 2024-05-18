#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

ll GCD(ll a, ll b){
	if(a%b==0){
		return b;
	}
	return GCD(b,a%b);
}

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0),diff(n-1,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		if(n==1){
			cout<<1<<"\n";
			continue;
		}
		sort(v.begin(),v.end());
		for(ll i=0;i<n-1;++i){
			diff[i]=v[i+1]-v[i];
		}
		sort(diff.begin(),diff.end());
		ll x=diff[0];
		for(ll i=0;i<n-1;++i){
			if(x<diff[i]){
				x=GCD(diff[i],x);
			}else{
				x=GCD(x,diff[i]);
			}
		}
		bool flag=0;
		for(ll i=n-1;i>=1;--i){
			ll cur_diff=v[i]-v[i-1];
			// cout<<"fds"<<cur_diff<<endl;
			if(cur_diff>x){
				flag=1;
				v.push_back(v[i]-x);
				break;
			}
		}
		// cout<<x<<endl;
		if(!flag){
			v.push_back(x+v[n-1]);
		}
		ll ans=0;
		sort(v.begin(),v.end());
		// for(ll i=0;i<v.size();++i){
		// 	cout<<v[i]<<" ";
		// }cout<<endl;
		ll target=v[v.size()-1];
		// cout<<x<<" "<<target<<endl;
		for(ll i=0;i<v.size();++i){
			ans+=(target-v[i])/x;
		}
		cout<<ans<<"\n";
	} 
	return 0;
}