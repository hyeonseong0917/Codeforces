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
		// 감염되는 집을 최소화 했을 때 이 개수
		ll n,m;
		cin>>n>>m;
		vector<ll> v(m,0);
		for(ll i=0;i<m;++i){
			cin>>v[i];
		}
		if(m==1){
			cout<<2<<"\n";
			continue;
		}
		vector<ll> diff;
		sort(v.begin(),v.end());
		for(ll i=1;i<m;++i){
			diff.push_back(v[i]-v[i-1]-1);
		}
		diff.push_back(v[0]+n-v[m-1]-1);
		ll ans=0, cnt=0;
		sort(diff.rbegin(),diff.rend());
		for(ll i=0;i<diff.size();++i){
			if(diff[i]-cnt*2>0){
				ans+=max(1ll,diff[i]-cnt*2-1);
			}
			cnt+=2;
		}
		cout<<n-ans<<"\n";
	} 
	return 0;
}