#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
 
#define ll long long
 
int main() {
	// your code goe1s here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		// 1 2 3 4 5 ...
		// 0 0 0 0 0
		// 1 0 0 0 0
		
		
		// 1 0 0 0
		// 1 2 2 1
		// shift or tp
		ll teleport_num=0;
		vector<ll> c;
		cin>>n;
		vector<ll> v(n,0);
		++v[0];
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			c.push_back(a);
		}
		// 1 2 2 1
		// 1 0 1 0 1
		// 5 4 3 2 1 4 3 2 1
		ll tmp_max=1;
		teleport_num+=(c[0]-1);
		tmp_max=max(tmp_max,c[0]);
		for(ll i=0;i<n-1;++i){
			if(c[i]<c[i+1]){
				teleport_num+=c[i+1]-c[i];
				tmp_max=c[i+1];
			}else{
				tmp_max=max(tmp_max,c[i]);
			}
		}
		if(tmp_max<c[n-1]){
			teleport_num+=c[n-1]-tmp_max;	
		}
		
		cout<<teleport_num<<"\n";
	}
	return 0;
}