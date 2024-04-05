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
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		ll cnt=0;
		ll L=0, R=n-1;
		ll x=0;
		while(L<=R){
			if(L==R){
				// cout<<L<<" "<<x<<" "<<cnt<<" "<<v[L]<<endl;
				ll diff=v[R]-x;
				cnt+=((diff+1)/2);
				if(v[L]!=1){
					++cnt;
				}
				break;
			}
			if(x+v[L]<v[R]){
				x+=v[L];
				cnt+=v[L];
				++L;
			}else if(x+v[L]>=v[R]){
				cnt+=(v[R]-x+1);
				v[L]-=(v[R]-x);
				--R;
				x=0;
				if(v[L]==0) ++L;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}