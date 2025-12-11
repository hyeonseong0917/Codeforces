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
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		ll max_num=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			max_num=max(max_num,v[i]);
		}
		vector<ll> check(max_num+1,0);
		for(ll i=0;i<n;++i){
			++check[v[i]];
		}
		bool flag=0;
		for(ll i=1;i<=max_num;++i){
			if(check[i]%k!=0){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<0<<"\n";
			continue;
		}
		ll L=0, R=0;
		ll ans=0;
		map<ll,ll> m;
		while(L<=R && R<n){
			// R번째 원소 처리
			++m[v[R]];
			// L 떙기기
			while(m[v[R]]>check[v[R]]/k){
				--m[v[L]];
				++L;
			}
			// [L,R],[L+1,R],[L+2,R].....[R,R]까지의 구간을 전부 카운트
			ans+=R-L+1;
			// cout<<L<<" "<<R<<" "<<m[v[L]]<<" "<<m[v[R]]<<" "<<ans<<endl;
			++R;
			
		}
		cout<<ans<<"\n";
	} 
	return 0;
}