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
		// a: n개의 음이 아닌 정수들, 운없는 정수 T
		ll n,T;
		cin>>n>>T;
		vector<ll> v(n,0), ans(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		map<ll,ll> check;
		ll cnt=0;
		for(ll i=0;i<n;++i){
			if(check[v[i]]==0){
				check[v[i]]=1;
				if(check[T-v[i]]){
					check[T-v[i]]=-1;
				}
			}
		}
		for(ll i=0;i<n;++i){
			if(v[i]*2==T){
				if(cnt%2==0){
					ans[i]=1;
					++cnt;
				}else{
					ans[i]=0;
					++cnt;
				}
			}else{
				if(check[v[i]]==1){
					ans[i]=1;
				}else{
					ans[i]=0;
				}
			}
		}
		for(ll i=0;i<n;++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";
	} 
	return 0;
}