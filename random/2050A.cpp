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
		ll n,m;
		cin>>n>>m;
		ll cnt=0;
		ll ans=0;
		bool flag=0;
		for(ll i=0;i<n;++i){
			string s;
			cin>>s;
			ll cs=s.size();
			if(cnt+cs<=m && !flag){
				cnt+=cs;
				++ans;
			}else{
				flag=1;
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
}