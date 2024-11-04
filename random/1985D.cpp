#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		string s[n+1];
		for(ll i=0;i<n;++i){
			cin>>s[i];
		}
		ll top_y,top_x,down_y=-1,down_x=-1;
		bool is_find_top=0;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				if(s[i][j]=='#'){
					top_y=i;
					top_x=j;
					is_find_top=1;
					break;
				}
			}
			if(is_find_top) break;
		}

		bool is_find_down=0;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				if(s[i][j]=='#' && down_y<i){
					down_y=i;
					down_x=j;
				}
			}
		}
		ll y=(top_y+down_y)/2;
		ll x=down_x;
		cout<<y+1<<" "<<x+1<<"\n";
	}
	
	return 0;
}