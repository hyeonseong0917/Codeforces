#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long

ll n;
bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<2 && x<n);
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		cin>>n;
		string s[2];
		for(ll i=0;i<2;++i){
			cin>>s[i];
		}
		queue<pair<ll,ll>> q;
		if(n==2){
			if(s[1][0]=='>'){
				cout<<"YES"<<"\n";
			}else{
				cout<<"NO"<<"\n";
			}
			continue;
		}
		bool flag=0;
		bool visited[2][n+1];
		for(int i=0;i<2;++i){
			for(int j=0;j<n;++j){
				visited[i][j]=0;
			}
		}
		if(s[1][n-2]=='>'){
			q.push({0,n-2});
			q.push({1,n-3});
			visited[0][n-2]=1;
			visited[1][n-3]=1;
		}
		while(!q.empty()){
			int y=q.front().first;
			int x=q.front().second;
			q.pop();
			if(y==0 && x==0){
				flag=1;
				break;
			}
			if(y==1 && x==1){
				if(s[1][0]=='>'){
					q.push({0,0});
				}
			}else{
				if(isRange(y,x-2)){
					if(s[y][x-1]=='>' && visited[y][x-2]==0){
						q.push({y,x-2});
						visited[y][x-2]=1;
						if(isRange(y+1,x-1) && visited[y+1][x-1]==0){
							visited[y+1][x-1]=1;
							q.push({y+1,x-1});
						}
						if(isRange(y-1,x-1) && visited[y-1][x-1]==0){
							visited[y-1][x-1]=1;
							q.push({y-1,x-1});
						}	
					}
				}
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