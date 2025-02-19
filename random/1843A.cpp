#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long

ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
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
		sort(v.begin(),v.end());
		ll sum=0;
		ll L=0, R=n-1;
		while(L<=R){
			if(L==R){
				break;
			}
			sum+=v[R]-v[L];
			--R;
			++L;
		}
		cout<<sum<<"\n";
	} 	

	return 0;
}