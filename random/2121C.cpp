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
		ll n,m;
		cin>>n>>m;
		vector<ll> v[n];
		ll max_num=0;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				ll a;
				cin>>a;
				max_num=max(max_num,a);
				v[i].push_back(a);
			}
		}
		// cout<<max_num<<endl;
		vector<pair<ll,ll>> p;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				if(v[i][j]==max_num){
					p.push_back({i,j});
					// cout<<i<<" "<<j<<endl;
				}
			}
		}
		ll y=p[0].first;
		ll x=p[0].second;
		// y번째 행으로 고정했을 때 가능한지?
		// 열을 몇 번째로 가져가야 할 지?
		map<ll,ll> fst_check;
		ll fst_cnt=0;
		for(ll i=0;i<p.size();++i){
			if(p[i].first!=y){
				if(!fst_check[p[i].second]){
					++fst_check[p[i].second];
					++fst_cnt;
				}
			}else{
				continue;
			}
		}
		// x번째 열로 고정했을 때
		ll sed_cnt=0;
		map<ll,ll> sed_check;
		for(ll i=0;i<p.size();++i){
			if(p[i].second!=x){
				if(!sed_check[p[i].first]){
					++sed_check[p[i].first];
					++sed_cnt;
				}
			}else{
				continue;
			}
		}
		// cout<<y<<" "<<x<<" "<<fst_cnt<<" "<<sed_cnt<<endl;
		if(fst_cnt<=1 || sed_cnt<=1){
			cout<<max_num-1<<"\n";
		}else{
			cout<<max_num<<"\n";
		}

		// // 모두 같은 행인지?
		// bool is_same_r=1;
		// for(ll i=1;i<p.size();++i){
		// 	if(p[i].first!=p[0].first){
		// 		is_same_r=0;
		// 		break;
		// 	}
		// }
		// bool is_same_c=1;
		// for(ll i=1;i<p.size();++i){
		// 	if(p[i].second!=p[0].second){
		// 		is_same_c=0;
		// 		break;
		// 	}
		// }
		// if(is_same_r || is_same_c){
		// 	cout<<max_num-1<<"\n";
		// }else{
		// 	ll y=p[0].first;
		// 	ll x=p[0].second;
		// 	// 1. x번째 열로 고정
		// 	map<ll,ll>  fst_m;
		// 	ll fst_cnt=0;
		// 	for(ll i=0;i<p.size();++i){
		// 		ll cy=p[i].first;
		// 		ll cx=p[i].second;
		// 		if(p[i].second==x) continue;
		// 		// x번째 열이 아니라면?
		// 		if(!fst_m[cy]){
		// 			++fst_cnt;
		// 			++fst_m[cy];
		// 		}
		// 		// 몇 번째 행인지?
		// 	}
			
		// 	// 2. y번째 행으로 고정
		// 	map<ll,ll> sed_m;
		// 	ll sed_cnt=0;
		// 	for(ll i=0;i<p.size();++i){
		// 		ll cy=p[i].first;
		// 		ll cx=p[i].second;
		// 		if(p[i].first==y) continue;
		// 		// x번째 열이 아니라면?
		// 		if(!sed_m[cx]){
		// 			++sed_cnt;
		// 			++sed_m[cx];
		// 		}
		// 		// 몇 번째 행인지?
		// 	}
		// 	if(fst_cnt<=1 || sed_cnt<=1){
		// 		cout<<max_num-1<<"\n";
		// 	}else{
		// 		cout<<max_num<<"\n";
		// 	}
		// }
	} 
	return 0;
}
