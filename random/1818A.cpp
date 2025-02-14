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
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		string s[n];
		vector<bool> check(n,0);
		for(ll i=0;i<n;++i){
			cin>>s[i];
		}
		ll ans=1;
		for(ll i=1;i<n;++i){
			bool is_same=1;
			for(ll j=0;j<k;++j){
				if(s[i][j]!=s[0][j]){
					is_same=0;
					break;
				}
			}
			if(is_same){
				++ans;
			}
		}
		cout<<ans<<"\n";
	} 	

	return 0;
}