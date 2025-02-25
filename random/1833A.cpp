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
		ll n;
		cin>>n;
		cin>>s;
		map<string,ll> check;
		ll ans=0;
		for(ll i=0;i<n-1;++i){
			string tmp=s.substr(i,2);
			if(!check[tmp]){
				++ans;
				++check[tmp];
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
}