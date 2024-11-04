#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		string s[2];
		ll cnt=0;
		for(ll i=0;i<2;++i){
			cin>>s[i];
			for(ll j=0;j<n;++j){
				if(s[i][j]=='.'){
					++cnt;
				}
			}
		}
		if(n<=2 || cnt<=3){
			cout<<0<<"\n";
		}else{
			bool is_all_free=1;
			for(ll i=0;i<2;++i){
				for(ll j=0;j<n;++j){
					if(s[i][j]=='x'){
						is_all_free=0;
						break;
					}
				}
			}
			if(is_all_free){
				cout<<0<<"\n";
				continue;
			}
			bool is_all_blocked=1;
			for(ll i=0;i<2;++i){
				for(ll j=0;j<n;++j){
					if(s[i][j]=='.'){
						is_all_blocked=0;
						break;
					}
				}
			}
			if(is_all_blocked){
				cout<<0<<"\n";
				continue;
			}
			ll ans=0;
			for(ll i=0;i<=n-3;++i){
				vector<string> v;
				for(ll j=0;j<2;++j){
					string tmp="";
					for(ll k=i;k<i+3;++k){
						tmp+=s[j][k];
					}
					v.push_back(tmp);
				}
				if(v[0]=="x.x" && v[1]=="..."){
					++ans;
				}
				if(v[1]=="x.x" && v[0]=="..."){
					++ans;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}