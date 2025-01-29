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
		ll n,a,b;
		cin>>n>>a>>b;
		if(a+b>n-2 || abs(a-b)>1){
			cout<<-1<<"\n";
			continue;
		}
		if(a==0 && b==0){
			for(ll i=1;i<=n;++i){
				cout<<i<<" ";
			}cout<<"\n";
			continue;
		}
		vector<ll> ans(n,0);
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			v[i]=i+1;
		}
		ll L=0, R=n-1;
		ll idx=1;
		if(a<b){
			// b먼저
			while(a || b){
				ans[idx++]=v[L++];
				--b;
				if(a){
					ans[idx++]=v[R--];
					--a;
				}
			}
			for(ll i=L;i<R;++i){
				ans[idx++]=v[i];
			}
			ans[0]=v[R];
		}else{
			// a먼저
			bool is_same=0;
			if(a==b) is_same=1;
			while(a || b){
				ans[idx++]=v[R--];
				--a;
				if(b){
					ans[idx++]=v[L++];
					--b;
				}
			}
			if(is_same){
				for(ll i=L;i<R;++i){
					ans[idx++]=v[i];
				}
				ans[0]=v[R];
			}else{
				for(ll i=R;i>L;--i){
					ans[idx++]=v[i];
				}
				ans[0]=v[L];
			}
			
		}
		for(ll i=0;i<n;++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";
	} 
	return 0;
}