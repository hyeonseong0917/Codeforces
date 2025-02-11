#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long

bool comp(pair<ll,ll> a, pair<ll,ll> b){
	if(a.first==b.first){
		return a.second>b.second;
	}
	return a.first<b.first;
}

int main() {
	// your code goes here
	int t=1;
	cin>>t;
	// 1053
	while(t--){
		// hero: power, monster: armor
		// n caves
		// cave i => k[i] monsters, a[i][1], a[i][2]..a[i][k[i]]
		// monster 쓰러뜨리면 power 1 dhffkrka
		// 가장 최소의 레벨 모든 몬스터 쓰러뜨리기 위한
		ll n;
		cin>>n;
		vector<vector<ll>> v;
		ll L=2023101800;
		ll R=-2023101800;
		vector<pair<ll,ll>> ticket;
		for(ll i=0;i<n;++i){
			ll m;
			cin>>m;
			vector<ll> tmp;
			ll max_num=0;
			for(ll j=0;j<m;++j){
				ll a;
				cin>>a;
				tmp.push_back(a);
				L=min(L,a);
				R=max(R,a);
				max_num=max(max_num,tmp[j]-j);
			}
			v.push_back(tmp);
			ticket.push_back({max_num,m});
			// 인덱스와 입장 조건 묶기
		}
		sort(ticket.begin(),ticket.end(),comp);
		// 모든 던전을 클리어하기 위한 가장 최소의 힘은
		// v[0]={10,15,8}
		// c[i]=v[i]-i
		// c[0] -> 클리어 하기 위한 입장 조건
		// c[0]={10,14,6} -> 14

		// v[1]={12,11}
		// c[1]={12,10} -> 12

		// v[2]={12,13,15}
		// c[2]={12,12,13} -> 13

		// v[3]={12,13,14,15,16}
		// c[3]={12,12,12,12,12} ->12
		// {12,5},{12,6}
		// 최대 입장 조건이 가장 작은 순부터 입장
		// 최대 입장 조건 같다면 사이즈가 큰 것부터 입장
		++L;
		++R;
		ll ans=R;
		while(L<=R){
			ll mid=(L+R)/2;
			// mid로 클리어 가능?
			// v의 던전들 중 어떤 던전을 먼저 들어가야할까??
			// 클리어가 가능한 던전
			// 1. 입장 조건을 봐야됨 v[0][0]보다 mid가 큰지지
			bool flag=1;
			ll cur_power=mid;
			for(ll i=0;i<n;++i){
				if(cur_power<=ticket[i].first){
					flag=0;
					break;
				}else{
					cur_power+=ticket[i].second;
				}
			}
			if(flag){
				ans=min(ans,mid);
				R=mid-1;
			}else{
				L=mid+1;
			}
		}
		cout<<ans<<"\n";
	} 	

	return 0;
}