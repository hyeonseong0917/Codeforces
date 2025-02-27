#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
bool visited[2][200000+1];
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		string board[2];
		for(ll i=0;i<2;++i){
			cin>>board[i];
		}
		for(ll i=0;i<2;++i){
			for(ll j=0;j<n;++j){
				visited[i][j]=0;
			}
		}
		bool flag=0;
		// 0,0에서 출발
		if(board[0][0]=='B'){
			ll y=0, x=0;
			visited[0][0]=1;
			bool is_clear=1;
			while(1){
				// 상하 이동 가능?
				if(y==0){
					if(!visited[y+1][x] && board[y+1][x]=='B'){
						visited[y+1][x]=1;
						++y;
					}else{
						++x;
						if(x==n){
							break;
						}
						visited[y][x]=1;
						if(board[y][x]=='W'){
							is_clear=0;
							break;
						}
					}
				}else{
					if(!visited[y-1][x] && board[y-1][x]=='B'){
						visited[y-1][x]=1;
						--y;
					}else{
						++x;
						if(x==n){
							break;
						}
						visited[y][x]=1;
						if(board[y][x]=='W'){
							is_clear=0;
							break;
						}
					}
				}
			}
			if(is_clear){
				flag=1;
			}
		}
		for(ll i=0;i<2;++i){
			for(ll j=0;j<n;++j){
				visited[i][j]=0;
			}
		}
		// 1,0에서 출발
		if(board[1][0]=='B'){
			ll y=1, x=0;
			visited[1][0]=1;
			bool is_clear=1;
			while(1){
				// 상하 이동 가능?
				if(y==0){
					if(!visited[y+1][x] && board[y+1][x]=='B'){
						visited[y+1][x]=1;
						++y;
					}else{
						++x;
						if(x==n){
							break;
						}
						visited[y][x]=1;
						if(board[y][x]=='W'){
							is_clear=0;
							break;
						}
					}
				}else{
					if(!visited[y-1][x] && board[y-1][x]=='B'){
						visited[y-1][x]=1;
						--y;
					}else{
						++x;
						if(x==n){
							break;
						}
						visited[y][x]=1;
						if(board[y][x]=='W'){
							is_clear=0;
							break;
						}
					}
				}
			}
			if(is_clear){
				flag=1;
			}
		}
		if(flag){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
	} 
	return 0;
}