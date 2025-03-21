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
bool comp(pair<ll,ll> a, pair<ll,ll> b){
	if(a.first==b.first){
		return a.second>b.second;
	}
	return a.first>b.first;
}
int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		// 10101
		string s;
		cin>>s;
		ll cnt=0;
		for(ll i=0;i<s.size();++i){
			if(s[i]=='1'){
				++cnt;
			}
		}
		cout<<cnt<<"\n";
		
	} 
	return 0;
}