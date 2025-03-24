#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
 
#define ll long long
ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
ll lcm(ll a, ll b){
	return (a*b)/gcd(a,b);
}

int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		// 1528
		// n*n의 테이블, n은 k의 배수이고
		// .와 x가 써있다면	
		ll n,k,r,c;
		cin>>n>>k>>r>>c;
		// r,c에는 'X'가 있음
		// 필요한 최소의 X개수
		vector<string> board;
		--r;
		--c;
		for(ll i=0;i<n;++i){
			string s="";
			for(ll j=0;j<n;++j){
				s+='.';
			}
			board.push_back(s);
		}
		for(ll i=0;i<n;++i){
			for(ll j=0;j<n;++j){
				if((i+j)%k==(r+c)%k){
					board[i][j]='X';
				}
			}
		}
		for(ll i=0;i<n;++i){
			for(ll j=0;j<n;++j){
				cout<<board[i][j];
			}cout<<"\n";
		}
	} 
	return 0;
}