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
		string s;
		cin>>s;
		vector<ll> v;
		for(ll i=0;(ll)pow(2,i)<=1000000000000000000;++i){
			v.push_back((ll)pow(2,i));
		}
		ll ans=s.size()+1;
		for(ll i=0;i<v.size();++i){
			string t=to_string(v[i]);
			ll s_idx=0;
			ll t_idx=0;
			ll same_cnt=0;
			while(s_idx<s.size() && t_idx<t.size()){
				if(s[s_idx]==t[t_idx]){
					++same_cnt;
					++s_idx;
					++t_idx;
				}else{
					++s_idx;
				}
			}
			ans=min(ans,s.size()-same_cnt+t.size()-same_cnt);
		}
		cout<<ans<<"\n";
	} 

	return 0;
}