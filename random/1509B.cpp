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
		ll n;
		cin>>n;
		string s;
		cin>>s;
		// TMTMTT
		// TTMMTT
		// T/T/M/M/T/T/M/T/T
		// T/T/T/T/M/M
		// TMTMMTTMTT
		// 1. M전에 M의 개수<=T의 개수여야함
		// 2. 남은 T의 개수(T의 개수 - M의 개수)=n-M의개수*2
		ll t_cnt=0, m_cnt=0;
		vector<ll> t_dp(n,0), m_dp(n,0);
		vector<ll> rt_dp(n,0), rm_dp(n,0);
		if(s[0]=='T'){
			++t_dp[0];
		}else{
			++m_dp[0];
		}
		if(s[n-1]=='T'){
			++rt_dp[n-1];
		}else{
			++rm_dp[n-1];
		}
		for(ll i=0;i<n;++i){
			if(s[i]=='T'){
				++t_cnt;
			}else{
				++m_cnt;
			}
		}
		if(t_cnt!=m_cnt*2){
			cout<<"NO"<<"\n";
			continue;
		}
		for(ll i=1;i<n;++i){
			t_dp[i]=t_dp[i-1];
			m_dp[i]=m_dp[i-1];
			if(s[i]=='T'){
				++t_dp[i];
			}else{
				++m_dp[i];
			}
		}
		for(ll i=n-2;i>=0;--i){
			rt_dp[i]=rt_dp[i+1];
			rm_dp[i]=rm_dp[i+1];
			if(s[i]=='T'){
				++rt_dp[i];
			}else{
				++rm_dp[i];
			}
		}
		bool flag=0;
		// 012345678
		// TTTTMMMTT
		for(ll i=0;i<n;++i){
			if(s[i]=='M'){
				if(m_dp[i]>t_dp[i] || i==n-1){
					flag=1;
					break;
				}
			}
		}
		
		for(ll i=n-1;i>=0;--i){
			if(s[i]=='M'){
				if(rm_dp[i]>rt_dp[i] || i==0){
					flag=1;
					break;
				}
			}
		}
		if(flag){
			cout<<"NO"<<"\n";
			continue;
		}
		cout<<"YES"<<"\n";
	} 
	return 0;
}