#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
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
	int t=1;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		if(n%2==1){
			cout<<"NO"<<"\n";
			continue;
		}
		// b[i-1]<b[i] && b[i]>b[i+1]
		// b[i-1]>b[i] && b[i]<b[i+1]
		// 둘 중 하나를 만족
		sort(v.begin(),v.end());
		vector<ll> ans(n,0);
		// ans[0]=v[0];
		// ans[n-1]=v[n-1];
		if(v[0]==v[n-1]){
			cout<<"NO"<<"\n";
			continue;
		}
		ll L=1, R=n/2;
		ans[0]=v[0];
		for(ll i=1;i<n;++i){
			if(i%2==1){
				ans[i]=v[R++];
			}else{
				ans[i]=v[L++];
			}
		}
		bool flag=0;
		// if(ans[0]==ans[1] || ans[n-1]==ans[n-2] || ans[0]==ans[n-1]){
		// 	flag=1;
		// }
		// cout<<ans[1]<<endl;

		for(ll i=0;i<n;++i){
			ll fst_idx=(i+n-1)%n;
			ll sed_idx=(i+1)%n;
			if((ans[i]>ans[sed_idx] && ans[i]>ans[fst_idx]) || (ans[i]<ans[sed_idx] && ans[i]<ans[fst_idx])) continue;
			flag=1;
		}
		if(flag){
			cout<<"NO"<<"\n";
		}else{
			cout<<"YES"<<"\n";
			for(ll i=0;i<n;++i){
				cout<<ans[i]<<" ";
			}cout<<"\n";
		}

	} 
	return 0;
}