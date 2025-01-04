#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	cin>>o;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		if(n==1){
			cout<<1<<"\n";
			continue;
		}
		ll L=1, R=v[n-1]-v[0];
		ll ans=R;
		ll INF=ans;
		while(L<=R){
			ll mid=(L+R)/2;
			// cout<<L<<" "<<R<<" "<<ans<<endl;
			ll idx=0;
			ll fst_max_diff=1, sed_max_diff=1;
			// ll max_diff=1;
			// 앞에 추가했을 경우
			if(n%2==0){
				ll max_diff=1;
				// 짝수일 때는 추가할 수 없음
				while(idx<n-1){
					max_diff=max(max_diff,v[idx+1]-v[idx]);
					idx+=2;
				}
				if(max_diff<=mid){
					ans=min(ans,mid);
					R=mid-1;
				}else{
					L=mid+1;
				}
			}else{
				// 홀수 일때는 특정 수를 없애볼 수 있음
				ll max_diff=INF;
				for(ll i=0;i<n;++i){
					// i번째 수 제거
					ll idx=0;
					ll cur_max_diff=1;
					while(idx<n-1){
						// idx와 idx+1확인
						if(idx==i){
							++idx;
							continue;
						}
						if(idx+1==i){
							cur_max_diff=max(cur_max_diff,v[idx+2]-v[idx]);
							idx+=3;
						}else{
							cur_max_diff=max(cur_max_diff,v[idx+1]-v[idx]);
							idx+=2;
						}
					}
					max_diff=min(max_diff,cur_max_diff);
				}
				if(max_diff<=mid){
					R=mid-1;
					ans=min(ans,mid);
				}else{
					L=mid+1;
				}
			}
			
		}
		cout<<ans<<"\n";
	}
	return 0;
}