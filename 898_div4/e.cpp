#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	vector<ll> v;
	ll n,x;
	while(t--){
		v.clear();
		cin>>n>>x;
		ll L=1222232421;
		ll R=-1;
		for(int i=0;i<n;++i){
			ll a=0;
			cin>>a;
			L=min(L,a);
			R=max(R,a+x/n);
			v.push_back(a);
		}
		ll ans=-1;
		while(L<=R){
			ll cur_h=(L+R)/2;
			ll cur_sum=0;
			bool flag=0;
			for(int i=0;i<v.size();++i){
				if(v[i]>=cur_h) continue;
				cur_sum+=(cur_h-v[i]);
				if(cur_sum>x){
					flag=1;
					break;
				}
			}
			if(flag){
				// cur_h가 너무 높음
				R=cur_h-1;
			}else{
				ans=max(ans,cur_h);
				L=cur_h+1;
			}
		}
		cout<<ans<<"\n";
		
	}
	return 0;
}