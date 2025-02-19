#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long

ll n;
ll dy[4]={-1,0,1,0};
ll dx[4]={0,1,0,-1};
bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<n && x<n);
}
int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		// n*n의 매트릭스
		// beauty를 정의함
		// x와 이웃한 y에 대해 |x-y|를 쓴다.
		// 그 사이 수 중 다른 숫자를 찾는다?
		// beauty가 최대로 되도록 하는
		// 1에서 n*n까지
		cin>>n;
		vector<ll> v;
		vector<vector<ll>> board;
		for(ll i=1;i<=n*n;++i){
			v.push_back(i);
		}
		for(ll i=0;i<n;++i){
			vector<ll> tmp;
			for(ll j=0;j<n;++j){
				tmp.push_back(0);
			}
			board.push_back(tmp);
		}
		ll cnt=0;
		ll cur_num=1;
		ll L=1, R=n*n;
		ll y=0, x=0;
		while(cnt<n){
			ll cy=y;
			ll cx=x;
			while(isRange(cy,cx)){
				if(cnt%2==0){
					board[cy][cx]=L++;
				}else{
					board[cy][cx]=R--;
				}
				--cy;
				++cx;
			}
			++y;
			x=0;
			++cnt;
		}
		
		y=n-1, x=1;
		while(cnt<(n-1)*2+1){
			ll cy=y;
			ll cx=x;
			while(isRange(cy,cx)){
				if(cnt%2==0){
					board[cy][cx]=L++;
				}else{
					board[cy][cx]=R--;
				}
				--cy;
				++cx;
			}
			++x;
			y=n-1;
			++cnt;
		}
		for(ll i=0;i<n;++i){
			for(ll j=0;j<n;++j){
				cout<<board[i][j]<<" ";
			}cout<<"\n";
		}
		// n<=50
		// 1 8 3 
		// 9 2 7
		// 4 6 5

		// 1 15
		// 16 
		
	} 	

	return 0;
}