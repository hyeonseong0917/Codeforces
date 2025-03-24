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
		vector<ll> c(n,0);
		for(ll i=0;i<n;++i){
			cin>>c[i];
		}
		if(n==1){
			if(c[0]!=1){
				cout<<"NO"<<"\n";
			}else{
				cout<<"YES"<<"\n";
			}
			continue;
		}
		sort(c.begin(),c.end());
		vector<ll> v(1,1);
		ll sum=1;
		bool flag=0;
		for(ll i=1;i<n;++i){
			if(c[i]==v[i-1]){
				v.push_back(c[i]);
				sum+=c[i];
			}else{
				ll diff=c[i]-c[i-1];
				if(diff>sum-c[i-1]){
					flag=1;
					break;
				}else{
					sum+=c[i];
					v.push_back(c[i]);
				}
			}
		}
		if(flag){
			cout<<"NO"<<"\n";
		}else{
			cout<<"YES"<<"\n";
		}
	} 
	return 0;
}