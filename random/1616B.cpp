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
		ll n;
		cin>>n;
		string s;
		cin>>s;
		if(n==1){
			cout<<s<<s<<"\n";
			continue;
		}
		// k번째 인덱스까지 취하고, 뒤집었을때 사전순으로 최소가 되도록?
		bool flag=0;
		for(ll i=1;i<n;++i){
			if(s[i]!=s[0]){
				flag=1;
			}
		}
		if(!flag || s[0]==s[1]){
			string k="";
			k+=s[0];
			k+=s[0];
			cout<<k<<"\n";
			continue;
		}
		ll idx=0;
		for(ll i=1;i<n;++i){
			if(s[i]>s[i-1]){
				break;
			}
			idx=i;
		}
		string ans="";
		string k=s.substr(0,idx+1);
		string p=k;
		reverse(p.begin(),p.end());
		ans=k+p;
		cout<<ans<<"\n";
	} 
	return 0;
}
