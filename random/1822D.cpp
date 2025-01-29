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
		ll n;
		cin>>n;
		if(n==1){
			cout<<1<<"\n";
			continue;
		}
		if(n%2==1){
			cout<<-1<<"\n";
		}else{
			// n=6
			// 6 5 1 4 2 3
			//   5 1 4 3 2 
			vector<ll> v(n-1,0);
			vector<ll> ans(n,0);
			ans[0]=n;
			ll R=n-1;
			ll L=1;

			for(ll i=0;i<n-1;++i){
				if(i%2==0){
					v[i]=R--;
				}else{
					v[i]=L++;
				}
			}
			ans[1]=n-1;
			for(ll i=1;i<n-1;++i){
				// v[i]와 v[i-1]의 거리
				if(v[i-1]<v[i]){
					ans[i+1]=v[i]-v[i-1];
				}else{
					ans[i+1]=n-v[i-1]+v[i];
				}
			}
			for(ll i=0;i<n;++i){
				cout<<ans[i]<<" ";
			}cout<<"\n";
			// for(ll i=0;i<n-1;++i){
			// 	cout<<v[i]<<" ";
			// }cout<<"\n";
		}
	} 
	return 0;
}