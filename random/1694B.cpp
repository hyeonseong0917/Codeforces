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
		ll ans=0;
		for(ll i=1;i<=n;++i){
			ans+=i;
		}
		for(ll i=0;i<n-1;++i){
			if(s[i]==s[i+1]){
				ans-=i+1;
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
}