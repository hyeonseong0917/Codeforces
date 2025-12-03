#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		ll ss=s.size();
		if(ss==1){
			cout<<1<<"\n";
			continue;
		}
		bool flag=0;
		for(ll i=0;i<ss-1;++i){
			string tmp=s.substr(i,2);
			if(tmp=="**"){
				flag=1;
			}
			if(tmp==">*"){
				flag=1;
			}
			if(tmp=="*<"){
				flag=1;
			}
			if(tmp=="><"){
				flag=1;
			}
		}
		ll ans=0;
		if(flag){
			cout<<-1<<"\n";
		}else{
			// >>>
			ll fst_cnt=0;
			for(ll i=0;i<ss;++i){
				if(s[i]=='>' || s[i]=='*'){
					++fst_cnt;
					ans=max(ans,fst_cnt);
				}else{
					fst_cnt=0;
				}
			}
			// <<<
			ll sed_cnt=0;
			for(ll i=ss-1;i>=0;--i){
				if(s[i]=='<' || s[i]=='*'){
					++sed_cnt;
					ans=max(ans,sed_cnt);
				}else{
					sed_cnt=0;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}