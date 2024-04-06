#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll x2=1222232421;
		ll x1=-1;
		vector<ll> v;
		for(ll i=0;i<n;++i){
			ll a,k;
			cin>>a>>k;
			if(a==1){
				x1=max(x1,k);
			}else if(a==2){
				x2=min(x2,k);
			}else{
				v.push_back(k);
			}
		}
		ll ans=x2-x1+1;
		for(ll i=0;i<v.size();++i){
			if(x1<=v[i] && v[i]<=x2){
				--ans;
			}
		}
		cout<<max(ans,(ll)0)<<"\n";
	}
	
	return 0;
}