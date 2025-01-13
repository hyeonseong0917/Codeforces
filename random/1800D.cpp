#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
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
		queue<char> q;
		for(ll i=2;i<n;++i){
			q.push(s[i]);
		}
		ll ans=1;
		for(ll i=0;i<=n-3;++i){
			char c=s[i];
			char k=q.front();
			q.pop();
			if(c!=k){
				++ans;
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
}