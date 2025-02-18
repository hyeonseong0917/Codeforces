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
		// 길이 m
		// 0에서 9까지의 숫자로 이루어져야함
		// 데이터베이스에 subsequence가 없어야함
		// l,r은 길이 m의 문자열
		// i번째 문자는 l[i]와 r[i] 사이에 있어야함
		string s;
		cin>>s;
		ll n=s.size();
		ll m;
		cin>>m; // m<=10
		string l,r;
		cin>>l;
		cin>>r;
		if(n<m){
			cout<<"YES"<<"\n";
			continue;
		}
		// 길이 m의 문자열을 만드려고함
		
		// l[i]<=r[i]
		// l[i]와 r[i]사이의 수로 새 비밀번호를 구성할 때
		// s의 서브시퀀스가 되지 않도록
		// m번째 수부터, s의 [m,n-1]에서 l[i]<=x<=r[i]
		// 가 존재하는지 확인. 없다면 가능
		// 있다면 가장 뒤에 있는 인덱스
		// dp[x][y]: n-1에서부터 x인덱스까지 y가 있는 가장 마지막 idx
		vector<vector<ll>> dp;
		for(ll i=0;i<n;++i){
			vector<ll> tmp(10,-1);
			dp.push_back(tmp);
		}
		for(ll i=n-1;i>=0;--i){
			ll c=s[i]-'0';
			for(ll j=0;j<10;++j){
				if(c==j){
					dp[i][j]=i;
				}else{
					if(i+1<=n-1){
						dp[i][j]=dp[i+1][j];
					}
				}
			}
		}
		bool flag=0;
		ll last_idx=0;
		for(ll i=0;i<m;++i){
			if(flag) break;
			if(last_idx>=n){
				flag=1;
				break;
			}
			ll L=l[i]-'0';
			ll R=r[i]-'0';
			ll idx=last_idx;
			for(ll j=L;j<=R;++j){
				ll cur_idx=last_idx;
				// while(cur_idx<n && s[cur_idx]!=(j+'0')){
				// 	++cur_idx;
				// }
				if(dp[cur_idx][j]==-1){
					flag=1;
					break;
				}
				idx=max(idx,dp[cur_idx][j]);
			}
			last_idx=idx+1;
		}
		if(flag){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}

	} 	

	return 0;
}