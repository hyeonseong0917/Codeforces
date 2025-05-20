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
	int t=1;
	cin>>t;
	while(t--){
		// 1134
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		// 1<=i<n 골라서, a[i]와 a[i+1]에 min(a[i],a[i+1])을 뺌
		// 비내림차순으로 만들 수 있는지??
		// 4 5 2 3 2 2
		// 0 1 2 3 2 2
		// 0 0 1 5 2 2
		// 0 0 0 2 2 2
		// 0 0 0
		if(v[0]>v[1]){
			cout<<"NO"<<"\n";
		}else{
			for(ll i=1;i<n;++i){
				ll a=min(v[i],v[i-1]);
				v[i]-=a;
				v[i-1]-=a;
			}
			bool flag=0;
			for(ll i=0;i<n;++i){
				if(v[i]<0){
					flag=1;
				}
			}
			for(ll i=0;i<n-1;++i){
				if(v[i]){
					flag=1;
				}
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