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
	int t=0;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		// 각 열의 MEX값의 최댓값
		// 각 행은 순열임(0에서 n-1까지의 값이 한 번씩)
		// 4 5
		// MEX 0을 만드는 방법-> 0만 없으면 됨
		// MEX 1을 만드는 방법 -> 0 있고 1만 없으면 됨
		// MEX 2를 만드는 방법 -> 0,1있고 2만 없으면 됨
		if(n==1 || m==1){
			if(n==1){
				// n==1
				if(m==1){
					cout<<0<<"\n";
					cout<<0<<"\n";
				}else{
					cout<<2<<"\n";
					for(ll j=0;j<m;++j){
						cout<<j<<" ";
					}cout<<"\n";
				}
			}else{
				// m==1
				cout<<0<<"\n";
				for(ll i=0;i<n;++i){
					cout<<0<<"\n";
				}cout<<"\n";
			}
			continue;
		}
		vector<vector<ll>> board;
		for(ll i=0;i<n;++i){
			vector<ll> tmp(m,-1);
			board.push_back(tmp);
		}
		ll cur_num=m-1;
		vector<ll> v;
		for(ll i=0;i<n;++i){
			board[i][0]=cur_num;
			v.push_back(cur_num);
			--cur_num;
			if(cur_num==0){
				break;
			}
		}

		for(ll i=1;i<m;++i){
			if(i-1<=n-1){
				board[i-1][i]=0;
			}
			
			for(ll j=0;i+j<=n-1 && j<v.size();++j){
				board[i+j][i]=v[j];
				if(v[j]==i+1){
					break;
				}
			}
			if(i>=2){
				for(ll j=0;i-2-j>=0 && i-2-j<=n-1;++j){
					board[i-2-j][i]=j+1;
				}
			}
		}
		if(n>=m){
			for(ll j=0;m+j-1<=n-1;++j){
				for(ll i=0;i<m;++i){
					board[m+j-1][i]=board[0][i];
				}
			}
		}else{
			// n<m
			for(ll i=n+2;i<m;++i){
				for(ll j=0;j<n;++j){
					board[j][i]=board[j][i-1]+1;
				}
			}
		}
		ll MEX=0;
		if(n<m){
			MEX=n+1;
		}else{
			MEX=m;
		}
		cout<<MEX<<"\n";
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				cout<<board[i][j]<<" ";
			}cout<<"\n";
		}

	} 
	return 0;
}