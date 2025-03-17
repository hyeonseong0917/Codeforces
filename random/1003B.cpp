#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	int t=1;
	// cin>>t;
	while(t--){
		ll a,b,x;
		cin>>a>>b>>x;
		if(x==1){
			string ans="";
			for(ll i=0;i<a;++i){
				ans+='0';
			}
			for(ll i=0;i<b;++i){
				ans+='1';
			}
			cout<<ans<<"\n";
			continue;
		}
		// n=a+b
		// x개의 s[i]!=s[i+1]이 존재함
		// 3 3
		// 010101
		// x-1개의 s[i]!=s[i+1]을 설계하고
		// 010101..11111..00000
		// s[i+1]쭉 도배하고 마지막에 s[i]쭉 도배
		string s="";
		ll n=a+b;
		if(a<=b){
			s+='1';
			--b;
		}else{
			s+='0';
			--a;
		}
		ll cnt=0;
		for(ll i=0;i<n-1;++i){
			char k=('1'-s[i])+'0';
			if(k=='0'){
				--a;
			}else{
				--b;
			}
			s+=('1'-s[i])+'0';
			++cnt;
			if(cnt>=x-1){
				break;
			}
		}
		char c=s[s.size()-1];
		if(c=='0'){
			while(a--){
				s+='0';
			}
			while(b--){
				s+='1';
			}
		}else{
			while(b--){
				s+='1';
			}
			while(a--){
				s+='0';
			}
		}
		cout<<s<<"\n";

	} 	

	return 0;
}