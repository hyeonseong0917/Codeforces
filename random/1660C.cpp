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
		string s;
		cin>>s;
		ll n=s.size();
		vector<ll> check(26,0);
		ll ans=0;
		for(ll i=0;i<n;++i){
			if(check[s[i]-'a']){
				ans+=2;
				check=vector<ll>(26,0);
			}else{
				++check[s[i]-'a'];
			}
		}
		cout<<n-ans<<"\n";

		
	} 
	return 0;
}