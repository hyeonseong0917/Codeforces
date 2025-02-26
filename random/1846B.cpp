#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		string board[3];
		for(ll i=0;i<3;++i){
			cin>>board[i];
		}
		bool flag=0;
		char c;
		if(board[0][0]==board[1][1] && board[0][0]==board[2][2] && board[0][0]!='.'){
			flag=1;
			c=board[0][0];
		}
		if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2]!='.'){
			flag=1;
			c=board[0][2];
		}
		
		for(ll i=0;i<3;++i){
			bool tmp=0;	
			for(ll j=0;j<3;++j){
				if(board[i][j]!=board[i][0]){
					tmp=1;
				}
			}
			if(!tmp && board[i][0]!='.'){
				flag=1;
				c=board[i][0];
			}
			tmp=0;
			for(ll j=0;j<3;++j){
				if(board[j][i]!=board[0][i]){
					tmp=1;
				}
			}
			if(!tmp && board[0][i]!='.'){
				flag=1;
				c=board[0][i];
			}
		}
		if(flag){
			cout<<c<<"\n";
		}else{
			cout<<"DRAW"<<"\n";
		}
		
	} 
	return 0;
}