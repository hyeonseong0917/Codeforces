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
		// i에서 j는 가깝다 다른 k포인트가 없다면
		// j에서 k까지의 거리가 j에서 i까지의 거리보다 작은
		// 모든 점들에 대해 가까운?
		// 1 10 100
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		if(n>=3){
			cout<<"NO"<<"\n";
		}else{
			if(v[0]+1==v[1]){
				cout<<"NO"<<"\n";
			}else{
				cout<<"YES"<<"\n";
			}
		}

	} 	

	return 0;
}