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
		// f(x): x점을 커버하는 구간의 개수
		// l<=x<=r
		// f(y)<f(x) => 모든 y에 대해서 성립한다. ideal하다면
		// 몇 개의 구간을 제거해서 k점이 ideal하도록?

		ll n,k;
		cin>>n>>k;
		vector<pair<ll,ll>> v;
		bool flag=0;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			if(a==k || b==k){
				flag=1;
			}
			v.push_back({a,b});
		}
		// k점이 가장 많은 구간이 커버한 유일한 점이 되어야함
		// 1. 구간에 k값이 없다면 no
		// 2. 구간에 k값이 있는데, 같다면 그냥 yes
		// 3. k작같 k, k, k큰같 있어야함 두 ㄹ다
		if(!flag){
			cout<<"NO"<<"\n";
		}else{
			bool is_small=0;
			bool is_big=0;
			for(ll i=0;i<n;++i){
				ll a,b;
				a=v[i].first;
				b=v[i].second;
				if(a==k || b==k){
					if(b==k){
						is_small=1;
					}
					if(a==k){
						is_big=1;
					}
				}
			}
			if(is_small==1 && is_big==1){
				cout<<"YES"<<"\n";
			}else{
				cout<<"NO"<<"\n";
			}
		}
		
	} 	

	return 0;
}