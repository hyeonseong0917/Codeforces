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
		vector<ll> cnt(m+1,0);
		for(ll i=0;i<n;++i){
			ll c;
			cin>>c;
			for(ll j=0;j<c;++j){
				ll a;
				cin>>a;
				v[i].push_back(a);
				++cnt[a];
			}
		}
		bool cnt_check=0;
		for(ll i=1;i<=m;++i){
			if(!cnt[i]){
				cnt_check=1;
				break;
			}
		}
		if(cnt_check){
			cout<<"NO"<<"\n";
			continue;
		}
		vector<ll> tmp;
		vector<ll> check(m+1,0);
		vector<ll> visited(n,0);
		for(ll i=0;i<n;++i){
			bool flag=0;
			for(ll j=0;j<v[i].size();++j){
				if(cnt[v[i][j]]==1){
					flag=1;
					break;
				}
			}
			if(flag){
				++visited[i];
				for(ll j=0;j<v[i].size();++j){
					if(!check[v[i][j]]){
						++check[v[i][j]];
						tmp.push_back(v[i][j]);
					}
				}
			}
		}
		sort(tmp.begin(),tmp.end());
		ll ts=tmp.size();
		if(ts==m){
			ll cur_cnt=0;
			for(ll i=0;i<n;++i){
				if(!visited[i]){
					++cur_cnt;
				}
			}
			if(cur_cnt>=2){
				cout<<"YES"<<"\n";
			}else{
				cout<<"NO"<<"\n";
			}
			
		}else{
			cout<<"YES"<<"\n";
		}
	} 	

	return 0;
}