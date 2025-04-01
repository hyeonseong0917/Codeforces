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
		ll n;
		cin>>n;
		vector<ll> a(n,0),b(n,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		for(ll i=0;i<n;++i){
			cin>>b[i];
		}
		// 하나의 operation -> ++a[i]
		// 만약 i<n이고 a[i]<=a[i+1] 이거나
		// i==n이고 a[i]<=a[1]이라면
		// a가 b가 될 수 있을지??
		bool flag=0;
		for(ll i=0;i<n;++i){
			if(a[i]>b[i]){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<"NO"<<"\n";
		}else{
			for(ll i=0;i<n;++i){
				if(a[i]==b[i]) continue;
				if(b[i]<=b[(i+1)%n]+1) continue;
				flag=1;
				break;
			}
			if(flag){
				cout<<"NO"<<"\n";
			}else{
				cout<<"YES"<<"\n";
			}
		}
 
	} 
	return 0;
}