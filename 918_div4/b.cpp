#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long
vector<ll> v;
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--){
		char board[3][3];
		bool visited[3+1];
		int y,x;
		for(int i=0;i<3;++i){
			visited[i]=0;
			for(int j=0;j<3;++j){
				cin>>board[i][j];
				if(board[i][j]=='?'){
					y=i;
					x=j;
				}
			}
		}
		
		for(int i=0;i<3;++i){
			if(board[y][i] && i!=x){
				visited[board[y][i]-'A']=1;
			}
			if(board[i][x] && i!=y){
				visited[board[i][x]-'A']=1;
			}
		}
		char ans;
		for(int i=0;i<3;++i){
			if(!visited[i]){
				ans='A'+i;
				break;
			}
		}
		cout<<ans<<"\n";
		
		
	}
	return 0;
}