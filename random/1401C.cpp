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
		// 1529
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> tmp(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
			tmp[i]=v[i];
		}
		sort(tmp.begin(),tmp.end());
		ll min_num=tmp[0];
		// 0 1 2 3 4 5
		// 4 3 6 6 2 9
		
		// i번째 수 기준 (i+1~n)에서 가장 작은 수랑 교환
		bool flag=0;
		// 4 8 2
		for(ll i=0;i<n;++i){
			if(v[i]==tmp[i]) continue;
			if(gcd(v[i],min_num)!=min_num){
				flag=1;
				break;
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