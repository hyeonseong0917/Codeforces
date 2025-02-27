#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		vector<ll> v[n+1];
		for(ll i=0;i<n;++i){
			for(ll j=0;j<n;++j){
				ll a;
				cin>>a;
				v[i].push_back(a);
			}
		}
		// k번의 operation으로 v[y][x]와
		ll cnt=0;
		ll same_cnt=0;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<n;++j){
				if(v[i][j]!=v[n-1-i][n-1-j]){
					++cnt;
				}else{
					++same_cnt;
				}
			}
		}
		// cout<<cnt<<"\n";
		cnt/=2;
		if(cnt>k){
			cout<<"NO"<<"\n";
		}else{
			// k>=cnt
			if(n&1){
				cout<<"YES"<<"\n";
			}else{
				if(!((k-cnt)&1)){
					cout<<"YES"<<"\n";
				}else{
					cout<<"NO"<<"\n";
				}
			}
		}
	} 
	return 0;
}