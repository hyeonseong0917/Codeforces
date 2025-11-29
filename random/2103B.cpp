#include <iostream>
#include <algorithm>
#include <vector>
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
		// [l,r]의 substring을 reverse 할 수 있는 기회가 최대 1번 있음
		ll n;
		cin>>n;
		string s;
		cin>>s;
		char c='0';
		ll ans=0;
		for(ll i=0;i<n;++i){
			if(s[i]!=c){
				if(c=='0'){
					c='1';
				}else{
					c='0';
				}
				++ans;
			}
		}
		// 11110
		if(ans>=3){
			cout<<n+ans-2<<"\n";
		}else if(ans==2){
			cout<<n+ans-1<<"\n";
		}else{
			cout<<n+ans<<"\n";
		}
		
	} 
	return 0;
}