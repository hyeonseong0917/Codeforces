#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		// a에서 i와 i+1을 찾는다
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		ll ans=1;
		for(ll i=0;i<n-1;++i){
			ll c=(ll)abs(v[i]-v[i+1]);
			if(c<=1){
				ans=0;
				break;
			}
		}
		if(ans==0){
			cout<<0<<"\n";
		}else{
			// v[i]와 v[i+1]를 x로 변환
			ans=-1;
			for(ll i=0;i<n-1;++i){
				ll min_num=min(v[i],v[i+1]);
				ll max_num=max(v[i],v[i+1]);
				if(i==0){
					if(n==2){
						ans=-1;
						break;
					}else{
						ll c=v[i+2];
						ll d=c+1;
						ll e=c-1;
						if(min_num<=c && c<=max_num){
							ans=1;
							break;
						}
						if(min_num<=d && d<=max_num){
							ans=1;
							break;
						}
						if(min_num<=d && d<=max_num){
							ans=1;
							break;
						}
					}
				}else{
					ll c=v[i+2];
					ll d=c+1;
					ll e=c-1;
					if(min_num<=c && c<=max_num){
						ans=1;
						break;
					}
					if(min_num<=d && d<=max_num){
						ans=1;
						break;
					}
					if(min_num<=d && d<=max_num){
						ans=1;
						break;
					}
					c=v[i-1];
					d=c+1;
					e=c-1;
					if(min_num<=c && c<=max_num){
						ans=1;
						break;
					}
					if(min_num<=d && d<=max_num){
						ans=1;
						break;
					}
					if(min_num<=d && d<=max_num){
						ans=1;
						break;
					}
				}
			}
			cout<<ans<<"\n";
		}
	} 

	return 0;
}