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
		// a가 주어짐
		// a의 각 문자 다음에 임의의 문자가 추가될 수 있음
		// 현재 문자랑 같은건 못더함
		// 마지막에 현재 문자로 닫아줌
		string s;
		ll n;
		cin>>n;
		cin>>s;
		string ans="";
		ans+=s[0];
		ll idx=1;
		char c=s[0];
		while(idx<s.size()){
			if(s[idx]==c){
				++idx;
				if(idx==s.size()){
					break;
				}
				c=s[idx];
				ans+=c;
				++idx;
			}else{
				++idx;
			}
		}
		cout<<ans<<"\n";

	} 
	return 0;
}