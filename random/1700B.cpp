#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int o=1;
	cin>>o;
	while(o--){
		// 1145
		ll n;
		cin>>n;
		string s;
		cin>>s;
		// n자리 수를 더해서 팰린드롬이 되도록 하는
		// 99
		// 1. 9999999가 되도록(길이 n)
		// 2. 이미 앞자리가 9라면 1111111(길이 n+1)
		string ans="";
		if(s[0]=='9'){
			// 999
			// 988
			// 1111

			// 1000
			//  964
			// 1. 1000으로 만들기
			string to_add="";
			for(ll i=0;i<n;++i){
				ans+='0';
				to_add+='1';
			}
			// 99
			ans[n-1]=('9'-s[n-1]+1)+'0';
			for(ll i=n-2;i>=0;--i){
				ans[i]=('9'-s[i])+'0';
			}
			ll carry=0;
			for(ll i=n-1;i>=0;--i){
				ll c=(ans[i]-'0')+(to_add[i]-'0')+carry;
				if(c>=10){
					carry=1;
					ans[i]=(c-10)+'0';
				}else{
					carry=0;
					ans[i]=c+'0';
				}
			}
			cout<<ans<<"\n";
		}else{
			for(ll i=0;i<s.size();++i){
				ll c='9'-s[i];
				ans+='0'+c;
			}
			cout<<ans<<"\n";
		}
	} 

	return 0;
}