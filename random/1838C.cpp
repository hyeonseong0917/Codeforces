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
		ll n,m;
		cin>>n>>m;
		bool is_prime=1;
		for(ll i=2;i<=sqrt(m);++i){
			if(m%i==0){
				is_prime=0;
				break;
			}
		}
		if(!is_prime){
			ll cnt=1;
			for(ll i=0;i<n;++i){
				for(ll j=0;j<m;++j){
					cout<<cnt<<" ";
					++cnt;
				}cout<<"\n";
			}
		}else{
			ll cnt=1;
			vector<vector<ll>> v;
			for(ll i=0;i<n;++i){
				vector<ll> tmp;
				for(ll j=0;j<m;++j){
					tmp.push_back(cnt++);
				}
				v.push_back(tmp);
			}
			// 1 2 3 4 5
			// 6 7 8 9 10
			// 11 12 13 14 15
			// 16 17 18 19 20
			// 21 22 23 24 25

			// 홀수번째 -> 짝수번째
			for(ll i=0;i<n;++i){
				if(i%2==1){
					for(ll j=0;j<m;++j){
						cout<<v[i][j]<<" ";
					}cout<<"\n";
				}
			}
			for(ll i=0;i<n;++i){
				if(i%2==0){
					for(ll j=0;j<m;++j){
						cout<<v[i][j]<<" ";
					}cout<<"\n";
				}
			}
		}
	} 	

	return 0;
}