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
		ll n,m;
		cin>>n>>m;
		vector<ll> v(n+1,0);
		for(ll i=1;i<=n;++i){
			cin>>v[i];
		}
		bool flag=0;
		ll cnt=0;
		ll last_num=-1;
		for(ll i=1;i<=n;++i){
			if(last_num==v[i]){
				++cnt;
			}else{
				last_num=v[i];
				cnt=1;
			}
			if(cnt==m){
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