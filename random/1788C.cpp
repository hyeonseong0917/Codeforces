#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
ll psum[200000+1];
int main() {
	// your code goes here
	int t=0;
	ll o=1;
	while(o--){
		psum[1]=1;
		for(ll i=2;i<=200000;++i){
			psum[i]=psum[i-1]+i;
		}
	}
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		if(n%2==0){
			cout<<"NO"<<"\n";
		}else{
			if(n==1){
				cout<<"YES"<<"\n";
				cout<<1<<" "<<2<<"\n";
			}else{
				ll s=(psum[2*n]-psum[n-1])/n;
				vector<ll> v;
				for(ll i=1;i<=n;++i){
					if(i%2==1){
						v.push_back(i);
					}
				}
				for(ll i=1;i<=n;++i){
					if(i%2==0){
						v.push_back(i);
					}
				}
				vector<ll> ans;
				for(ll i=0;i<v.size();++i){
					ans.push_back(v[i]);
					ans.push_back(s+i-v[i]);
				}
				cout<<"YES"<<"\n";
				for(ll i=0;i<2*n;i+=2){
					cout<<ans[i]<<" "<<ans[i+1]<<"\n";
				}
			}
		}
	} 
	return 0;
}