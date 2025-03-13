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
		// 1322
		// n*m의 매트릭스
		// 0이나 1로 이루어짐
		// 2*2의 정사각형. 한 모서리 셀을 뺀 모양을 lshape
		// 최소 하나의 1이 포함된 lshape 선택
		// 이 도형의 모든 1을 0으로 바꿈
		// 최대한 많은 연산을 수행하는 것이 목표

		// 1 1 0
		// 1 0 1
		// 0 1 1

		// 1 0 0
		// 0 1 0
		// 1 1 0

		// 2*2에 0만 있다면 pass
		// 1이 1개라면? 그거 0으로 만들고 pass
		// 1이 2개라면?
		ll n,m;
		cin>>n>>m;
		string board[n+1];
		ll ans=0;
		for(ll i=0;i<n;++i){
			cin>>board[i];
			for(ll j=0;j<m;++j){
				if(board[i][j]=='1'){
					++ans;
				}
			}
		}
		
		// 0이 0개면 -2, 1개면 -1
		ll max_cnt=0;
		for(ll i=0;i<n-1;++i){
			for(ll j=0;j<m-1;++j){
				ll zero_cnt=0;
				for(ll k=0;k<2;++k){
					for(ll p=0;p<2;++p){
						if(board[i+k][j+p]=='0'){
							++zero_cnt;
						}
					}
				}
				max_cnt=max(max_cnt,zero_cnt);
			}
		}
		if(max_cnt<=1){
			ans+=max_cnt-2;
		}
		cout<<ans<<"\n";
	} 

	return 0;
}