#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long

ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
ll dy[4]={-1,0,1,0};
ll dx[4]={0,1,0,-1};
ll n,m;
bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<n && x<m);
}

int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		cin>>n>>m;
		vector<vector<ll>> board;
		for(ll i=0;i<n;++i){
			vector<ll> tmp;
			for(ll j=0;j<m;++j){
				ll a;
				cin>>a;
				tmp.push_back(a);
			}
			board.push_back(tmp);
		}
		vector<ll> check(n*m+1,0);
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				if(!check[board[i][j]]){
					check[board[i][j]]=1;
				}
				for(ll k=0;k<4;++k){
					ll ny=i+dy[k];
					ll nx=j+dx[k];
					if(!isRange(ny,nx)) continue;
					if(board[ny][nx]==board[i][j]){
						check[board[i][j]]=2;
					}
				}
			}
		}
		ll ans=0;
		ll max_num=0;
		for(ll i=1;i<=n*m;++i){
			if(check[i]){
				max_num=max(max_num,check[i]);
				ans+=check[i];
			}
		}
		cout<<ans-max_num<<"\n";
	} 	

	return 0;
}