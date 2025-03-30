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
		ll k;
		cin>>k;
		vector<ll> v(k,0);
		for(ll i=0;i<k;++i){
			cin>>v[i];
		}
		vector<ll> f(k+1,0);
		for(ll i=0;i<k;++i){
			++f[v[i]];
		}
		ll n,m;
		for(ll i=1;i<=k;++i){
			if(i*i==k-2){
				if(f[i]>1){
					n=i;
					m=i;
				}
			}else if((k-2)%i==0){
				if(f[i] && f[(k-2)/i]){
					n=i;
					m=(k-2)/i;
				}
			}
		}
		cout<<n<<" "<<m<<"\n";

	} 
	return 0;
}