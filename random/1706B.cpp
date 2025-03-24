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
		// n개의 색칠된 블럭들
		// i번째블럭의 색은 c[i]이다
		// 1과 n사이의 정수들
		// (0,0)에 1을 놓는다
		// 2<=i<=n에 대해 i-1번째 블럭이 (x,y)에 있었다면
		// i번째 블럭은 (x+1,y),(x-1,y),(x,y+1)중 하나에 있는다
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> g[n+1];
		for(ll i=0;i<n;++i){
			cin>>v[i];
			g[v[i]].push_back(i);
		}
		// 0 1 2 3 4 5 6
		// 1 2 3 1 2 3 1

		vector<ll> ans;
		
		for(ll i=0;i<n;++i){
			// i+1색의 최대 타워 크기
			ll c=i+1;
			ll max_len=1;
			if(g[c].empty()){
				ans.push_back(0);
				continue;
			}
			// 인덱스 차이가 홀수인 최대 길이
			// 0 1 2 3 4 5
			// 3 3 3 1 3 3

			// 0 1 2 4 5
			for(ll j=1;j<g[c].size();++j){
				if((g[c][j]-g[c][j-1])%2==1){
					++max_len;
				}
			}
			ans.push_back(max_len);
			
		}
		for(ll i=0;i<ans.size();++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";
	} 
	return 0;
}