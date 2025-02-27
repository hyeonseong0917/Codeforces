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
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		if(n==1){
			cout<<1<<"\n";
			continue;
		}
		sort(v.begin(),v.end());
		ll ans=0;
		ll L=0, R=n;
		
		while(L<=R){
			ll mid=(L+R)/2;
			// k=mid
			// 1부터 mid번의 라운드까지 진행
			// cout<<L<<" "<<R<<"\n";
			vector<ll> cv=v;
			bool flag=0;
			for(ll i=1;i<=mid;++i){
				ll cur_num=mid-i+1;
				// cur_num보다 작거나 같은 값 중 최댓값 삭제하기
				ll idx=-1;
				ll vs=v.size();
				vector<ll> tmp;
				for(ll j=vs-1;j>=0;--j){
					if(v[j]<=cur_num){
						idx=j;
						break;
					}
				}
				if(idx==-1){
					flag=1;
					break;
				}
				for(ll j=0;j<vs;++j){
					if(j==idx) continue;
					tmp.push_back(v[j]);
				}
				tmp[0]+=cur_num;
				v.clear();
				v=tmp;
				sort(v.begin(),v.end());
			}
			v.clear();
			v=cv;
			if(flag){
				R=mid-1;
			}else{
				ans=max(ans,mid);
				L=mid+1;
			}
		}
		cout<<ans<<"\n";
		
	} 
	return 0;
}