#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int o=1;
	cin>>o;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		ll sum=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			sum+=v[i];
		}
		if(n<=2){
			cout<<-1<<"\n";
			continue;
		}
		sort(v.begin(),v.end());
		// 가장 부유한 사람은 추가로 x를 얻음
		// 사람은 불행하다고 느낀다 전체 평균의 절반보다 낮으면
		// 절반보다 많은 사람이이 불행하다면 됨
		// 가장 최소의 x를 구한다. 아니면 -1

		// 1 2 3 4 5
		// 백만,백만..
		// 1백만*10만
		// 10000000000
		// 2백만*20만
		ll L=0, R=10000000000000;
		ll x=R;
		while(L<=R){
			ll mid=(L+R)/2;
			ll U=sum+mid;
			ll D=n*2;
			ll avg=(U+D-1)/D;
			ll cnt=0;
			for(ll i=0;i<n-1;++i){
				if(v[i]<avg){
					++cnt;
				}
			}
			if(cnt>n/2){
				x=min(x,mid);
				R=mid-1;
			}else{
				L=mid+1;
			}
		}
		cout<<x<<"\n";
	} 
	return 0;
}