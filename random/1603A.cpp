#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n+1,0);
		for(ll i=1;i<=n;++i){
			cin>>v[i];
		}
		bool flag=0;
		for(ll i=1;i<=n;++i){
			// v[i]가 2에서 i+1까지 안나누어지는 수가 있는지??
			bool is_find=0;
			ll sum=1;
			for(ll j=2;j<=i+1;++j){
				if(v[i]%j!=0){
					is_find=1;
					break;
				}
				sum*=j;
			}
			if(!is_find){
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