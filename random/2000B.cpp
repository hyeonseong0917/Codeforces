#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
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
		vector<ll> check(n+1,0);
		++check[v[0]];
		bool flag=0;
		for(ll i=1;i<n;++i){
			ll L=v[i]-1;
			ll R=v[i]+1;
			bool c=0;
			if(L>=1 && check[L]){
				c=1;
			}
			if(R<=n && check[R]){
				c=1;
			}
			if(!c){
				flag=1;
				break;
			}
			++check[v[i]];
		}
		if(flag){
			cout<<"NO"<<"\n";
		}else{
			cout<<"YES"<<"\n";
		}
	} 
	return 0;
}