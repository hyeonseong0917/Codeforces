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
	int t=1;
	cin>>t;
	while(t--){
		ll n,l,r;
		cin>>n>>l>>r;
		vector<ll> ans;
		bool flag=0;
		for(ll i=1;i<=n;++i){
			if(l%i==0){
				ans.push_back(l);
				continue;
			}
			ll c=i*((l/i)+1);
			if(c<=r){
				ans.push_back(c);
			}else{
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<"NO"<<"\n";
		}else{
			cout<<"YES"<<"\n";
			for(ll i=0;i<ans.size();++i){
				cout<<ans[i]<<" ";
			}cout<<"\n";
		}
	} 
	return 0;
}