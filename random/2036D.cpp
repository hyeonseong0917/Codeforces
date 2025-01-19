#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
ll n,m;
ll dy[4]={-1,0,1,0};
ll dx[4]={0,1,0,-1};
bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<n && x<m);
}
char get_pre(char c){
	if(c=='5'){
		return '1';
	}
	if(c=='4'){
		return '5';
	}
	if(c=='3'){
		return '4';
	}
}

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		cin>>n>>m;
		string board[n+1];
		ll dp[n][m];
		for(ll i=0;i<n;++i){
			cin>>board[i];
			for(ll j=0;j<m;++j){
				dp[i][j]=0;
				if(board[i][j]=='1') dp[i][j]=1;
			}
		}
		ll y=0, x=0;
		ll cnt=min((n/2),(m/2));
		// cout<<cnt;
		ll cur_cnt=0;
		ll y_step=n;
		ll x_step=m;
		ll ans=0;
		while(cnt--){
			string cur_str="";
			// cout<<cnt<<" "<<x+x_step<<endl;
			for(ll i=x;i<x+x_step-1;++i){
				cur_str+=board[y][i];
			}
			// cout<<cur_str<<endl;
			// break;
			for(ll i=y;i<y+y_step-1;++i){
				cur_str+=board[i][x+x_step-1];
			}
			// cout<<cur_str<<endl;
			// break;
			for(ll i=x+x_step-1;i>x;--i){
				cur_str+=board[y+y_step-1][i];
			}
			for(ll i=y+y_step-1;i>y;--i){
				cur_str+=board[i][x];
			}
			x+=1;
			y+=1;
			y_step-=2;
			x_step-=2;
			// cout<<cur_str<<"\n";
			ll cs=cur_str.size();
			if(cs<4) break;
			ll q_cnt=0;
			for(ll i=0;i<cs;++i){
				string tmp_str="";
				tmp_str+=cur_str[i];
				tmp_str+=cur_str[(i+1)%cs];
				tmp_str+=cur_str[(i+2)%cs];
				tmp_str+=cur_str[(i+3)%cs];
				if(tmp_str.compare("1543")==0){
					++ans;
				}
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
}