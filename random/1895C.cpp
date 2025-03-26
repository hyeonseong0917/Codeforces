#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

#define ll long long

bool comp(pair<ll,string> a, pair<ll,string> b){
	return a.first>b.first;
}

int main() {
	// your code goes here
	ll o=1;
	while(o--){
		// 1에서 9까지의 digit
		// 짝수의 길이를 가진다
		// 처음 절반의 digit의 합은 나중 절반의 digit합과 같다
		// n개의 티켓이 주어진다
		// 몇 개의 s[i]+s[j]티켓들이 lucky일까?
		// 홀수+홀수
		// 짝수+짝수
		// i==j인경우는 무조건 가능하니까 배제
		// 각 티켓의 크기는 최대 5

		// 처음 절반의 digit합과 나중 절반의 digit 합이 같아지는 방법?
		// 

		ll n;
		cin>>n;
		vector<pair<ll,string>> v;
		ll ans=0;
		vector<vector<ll>> dp;
		for(ll i=0;i<n;++i){
			string s;
			cin>>s;
			ll ss=s.size();
			v.push_back({ss,s});
		}
		for(ll i=0;i<=5;++i){
			vector<ll> tmp(45+1,0);
			dp.push_back(tmp);
		}
		sort(v.begin(),v.end(),comp);
		for(ll i=0;i<n;++i){
			ll cs=v[i].first;
			string cur_str=v[i].second;
			ll sum=0;
			for(ll j=0;j<cs;++j){
				sum+=(cur_str[j]-'0');
			}
			++dp[cs][sum];
		}
		for(ll i=0;i<n;++i){
			ll cs=v[i].first;
			string cur_str=v[i].second;
			if(cs<=2) break;
			ll half_sum=0;
			ll cur_sum=0;
			for(ll j=0;j<cur_str.size();++j){
				cur_sum+=cur_str[j]-'0';
			}
			if(cs==5){
				// 5+1
				half_sum=0;
				for(ll j=0;j<3;++j){
					half_sum+=cur_str[j]-'0';
				}
				ll c=max(0ll,half_sum-(cur_sum-half_sum));
				ans+=dp[1][c];
				// 1+5
				half_sum=0;
				for(ll j=2;j<5;++j){
					half_sum+=cur_str[j]-'0';
				}
				c=max(0ll,half_sum-(cur_sum-half_sum));
				ans+=dp[1][c];
				// 5+3
				half_sum=0;
				for(ll j=0;j<4;++j){
					half_sum+=cur_str[j]-'0';
				}
				c=max(0ll,half_sum-(cur_sum-half_sum));
				ans+=dp[3][c];
				// 3+5
				half_sum=0;
				for(ll j=1;j<5;++j){
					half_sum+=cur_str[j]-'0';
				}
				c=max(0ll,half_sum-(cur_sum-half_sum));
				ans+=dp[3][c];
			}else if(cs==4){
				// 4+2
				half_sum=0;
				for(ll j=0;j<3;++j){
					half_sum+=cur_str[j]-'0';
				}
				ll c=max(0ll,half_sum-(cur_sum-half_sum));
				ans+=dp[2][c];
				// 2+4
				half_sum=0;
				for(ll j=1;j<4;++j){
					half_sum+=cur_str[j]-'0';
				}
				c=max(0ll,half_sum-(cur_sum-half_sum));
				ans+=dp[2][c];
			}else if(cs==3){
				// 3+1
				half_sum=0;
				for(ll j=0;j<2;++j){
					half_sum+=cur_str[j]-'0';
				}
				ll c=max(0ll,half_sum-(cur_sum-half_sum));
				ans+=dp[1][c];
				// 1+3
				half_sum=0;
				for(ll j=1;j<3;++j){
					half_sum+=cur_str[j]-'0';
				}
				c=max(0ll,half_sum-(cur_sum-half_sum));
				ans+=dp[1][c];
			}
		}
		// cout<<ans<<endl;
		for(ll i=1;i<=5;++i){
			for(ll j=1;j<=i*9;++j){
				if(dp[i][j]>=2){
					ans+=((dp[i][j]-1)*dp[i][j]);
				}
			}
		}
		ans+=n;
		cout<<ans<<"\n";

	}
	
	return 0;
}