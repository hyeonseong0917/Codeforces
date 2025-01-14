#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	cin>>t;
	while(t--){
		ll n,m,d;
		cin>>n>>m>>d;
		vector<ll> p(n,0);
		vector<ll> a(m,0);
		vector<ll> pos;
		map<ll,ll> check;
		for(ll i=0;i<n;++i){
			cin>>p[i];
			check[p[i]]=i+1;
		}
		for(ll i=0;i<m;++i){
			cin>>a[i];
		}
		for(ll i=0;i<m;++i){
			pos.push_back(check[a[i]]);
		}
		// not good인지 체크
		bool flag=0; // 초기에 not good임
		ll ans=2023101800;
		for(ll i=1;i<m;++i){
			ll cur_diff=pos[i]-pos[i-1];
			ans=min(ans,cur_diff);
			if(!(cur_diff>0 && cur_diff<=d)){
				// 한 번이라도 not good 조건이 깨짐
				flag=1;
			}
		}
		if(flag){
			// good임
			cout<<0<<"\n";
		}else{
			// not good임
			// 현재 ans값은 pos[i]<pos[i+1]을 깨뜨리기 위한 최솟값
			// 이제 확인해 볼 것은 i번째 수를 옮겨서 차이를 d+1로 만들기
			for(ll i=1;i<m;++i){
				ll cur_diff=pos[i]-pos[i-1];
				ll new_diff=(d+1)-cur_diff; // 차이를 d+1로 만들기 위해 필요한 값
				ll L=pos[i-1]-1;
				ll R=n-pos[i];
				if(L+R>=new_diff){
					ans=min(ans,new_diff);
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}