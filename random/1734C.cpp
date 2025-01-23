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
		ll n;
		cin>>n;
		string k;
		cin>>k;
		// map<ll,ll> T;
		vector<ll> T(n+1,0);
		for(ll i=0;i<k.size();++i){
			if(k[i]=='1'){
				++T[i+1];
			}
		}
		// map<ll,ll> check;
		vector<ll> check(n+1,0);
		ll cost=0;
		for(ll i=1;i<=n;++i){
			if(T[i]) continue;
			for(ll j=1;i*j<=n;++j){
				if(!T[i*j]){
					if(!check[i*j]){
						check[i*j]=1;
						cost+=i;
					}
					// check[i*j]=i;
				}else{
					break;
				}
			}
		}
		// for(ll i=1;i<=n;++i){
		// 	if(!T[i]){
		// 		cost+=check[i];
		// 	}
		// }
		cout<<cost<<"\n";
	} 
	return 0;
}