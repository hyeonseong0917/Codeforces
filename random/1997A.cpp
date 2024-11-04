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
		string s;
		cin>>s;
		ll idx=-1;
		ll n=s.size();
		for(ll i=0;i<n-1;++i){
			if(s[i]==s[i+1]){
				idx=i;
				break;
			}
		}
		string ans="";
		if(idx==-1){
			
			if(s[0]=='a'){
				ans+='b';
			}else{
				ans+='a';
			}
			ans+=s;
		}else{
			
			ans+=s.substr(0,idx+1);
			if(s[idx]=='a'){
				ans+='b';
			}else{
				ans+='a';
			}
			for(ll i=idx+1;i<n;++i){
				ans+=s[i];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}