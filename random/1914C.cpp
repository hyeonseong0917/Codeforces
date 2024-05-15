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
		ll n,k;
		cin>>n>>k;
		vector<ll> a(n,0),b(n,0),c(n,0),psum(n,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
			psum[i]=(i==0)?a[i]:psum[i-1]+a[i];
			
		}
		ll cur_max_num=-1;
		for(ll i=0;i<n;++i){
			cin>>b[i];
			if(i==0){
				c[0]=b[0];
				cur_max_num=b[0];
			}else{
				if(cur_max_num<b[i]){
					cur_max_num=b[i];
				}
				c[i]=cur_max_num;
			}
		}
		ll ans=0;
		if(k<=n){
			for(ll i=k-1;i>=0;--i){
				ans=max(ans,psum[i]+(k-1-i)*c[i]);
			}
		}else{
			//k>n
			for(ll i=n-1;i>=0;--i){
				ans=max(ans,psum[i]+(k-(i+1))*c[i]);
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
}