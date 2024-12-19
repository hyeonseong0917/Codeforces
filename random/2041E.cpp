#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	while(t--){
		ll a,b;
		cin>>a>>b;
		vector<ll> ans(3,0);
		ans[0]=b;
		ans[1]=b;
		ans[2]=3*a-2*b;
		while(1){
			if(ans[0]<=b && b<=ans[2]){
				break;
			}
			--ans[0];
			++ans[2];
		}
		cout<<3<<"\n";
		for(ll i=0;i<3;++i){
			cout<<ans[i]<<" ";
		}
	}
	return 0;
}