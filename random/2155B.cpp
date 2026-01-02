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

int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		ll cycle_num=n*n-k;
		if(cycle_num==1){
			cout<<"NO"<<"\n";
			continue;
		}
		string board[n];
		for(ll i=0;i<n;++i){
			string tmp="";
			for(ll j=0;j<n;++j){
				tmp+='R';
			}
			board[i]=tmp;
		}
		if(cycle_num==0){
			cout<<"YES"<<"\n";
			for(ll i=0;i<n;++i){
				cout<<board[i]<<"\n";
			}	
			continue;
		}
		// RRR
		// RRR
		// RRR
		// cout<<cycle_num<<endl;
		for(ll i=0;i<n;++i){
			if(!cycle_num) break;
			if(cycle_num==1){
				--cycle_num;
				board[i][0]='U';
				break;
			}
			--cycle_num;
			for(ll j=1;j<n;++j){
				if(cycle_num){
					--cycle_num;
					board[i][j]='L';
				}
			}
		}
		for(ll i=0;i<n;++i){
			if(!cycle_num) break;
			if(cycle_num){
				--cycle_num;
				board[i][0]='D';
			}
		}
		cout<<"YES"<<"\n";
		for(ll i=0;i<n;++i){
			for(ll j=0;j<n;++j){
				cout<<board[i][j];
			}cout<<"\n";
		}


	} 	

	return 0;
}