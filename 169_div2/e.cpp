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
	ll o;
	cin>>o;
	while(o--){
		ll n,m,k;
		cin>>n>>m>>k;
		ll w;
		cin>>w;
		vector<ll> v(w,0);
		for(ll i=0;i<w;++i){
			cin>>v[i];
		}
		ll board[n+1][m+1];
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				board[i][j]=0;
			}
		}
		for(ll i=0;i<n;++i){
			if(i+k>n){
				break;
			}
			for(ll j=0;j<m;++j){
				if(j+k>m){
					break;
				}
				// cout<<i<<" "<<j<<endl;
				for(ll a=i;a<i+k;++a){
					for(ll b=j;b<j+k;++b){
						++board[a][b];
					}
				}
			}
		}
		// for(ll i=0;i<n;++i){
		// 	for(ll j=0;j<m;++j){
		// 		cout<<board[i][j]<<" ";
		// 	}cout<<endl;
		// }cout<<endl;
		vector<pair<ll,ll>> cnt[n*m+100000];
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				if(!board[i][j]) continue;
				cnt[board[i][j]].push_back({i,j});
				// cout<<i<<" "<<j<<endl;
			}
		}
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		ll idx=0;
		bool check[n+1][m+1];
		for(ll i=n*m;i>=1;--i){
			if(idx==w) break;
			if(cnt[i].empty()) continue;
			for(ll j=0;j<cnt[i].size();++j){
				if(idx==w) break;
				ll y=cnt[i][j].first;
				ll x=cnt[i][j].second;
				check[y][x]=1;
				board[y][x]=v[idx++];
				
			}
		}
		// for(ll i=0;i<n;++i){
		// 	for(ll j=0;j<m;++j){
		// 		cout<<board[i][j]<<" ";
		// 	}cout<<endl;
		// }
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				if(!check[i][j]){
					board[i][j]=0;
				}
			}
		}
		ll ans=0;
		for(ll i=0;i<n;++i){
			if(i+k>n){
				break;
			}
			for(ll j=0;j<m;++j){
				if(j+k>m){
					break;
				}
				// cout<<i<<" "<<j<<endl;
				for(ll a=i;a<i+k;++a){
					for(ll b=j;b<j+k;++b){
						ans+=board[a][b];
					}
				}
			}
		}
		// for(ll i=0;i<n;++i){
		// 	for(ll j=0;j<m;++j){
		// 		cout<<board[i][j];
		// 	}cout<<endl;
		// }
		cout<<ans<<"\n";
	}
	return 0;
}