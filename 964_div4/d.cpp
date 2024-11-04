#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o;
	cin>>o;
	while(o--){
		string s,t;
		cin>>s;
		cin>>t;
		ll s_idx=0;
		ll t_idx=0;
		ll sn=s.size();
		ll tn=t.size();
		while(s_idx<sn && t_idx<tn){
			if(s[s_idx]=='?'){
				s[s_idx]=t[t_idx];
				++s_idx;
				++t_idx;
			}else{
				if(s[s_idx]==t[t_idx]){
					++s_idx;
					++t_idx;
				}else{
					++s_idx;
				}
			}
		}
		for(ll i=0;i<sn;++i){
			if(s[i]=='?'){
				s[i]='a';
			}
		}
		if(t_idx==tn){
			cout<<"YES"<<"\n";
			cout<<s<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
	}
	return 0;
}