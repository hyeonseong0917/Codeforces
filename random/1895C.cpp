#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define ll long long

long add_digit(string s){
	ll ans=0;
	for(ll i=0;i<s.size();++i){
		ans+=s[i]-'0';
	}
	return ans;
}

int main() {
	// your code goes here
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<string> v[5+1];
		for(ll i=0;i<n;++i){
			string s;
			cin>>s;
			ll ss=s.size();
			v[ss].push_back(s);
		}
		ll ans=n;
		ll cnt=0;
		map<ll,ll> m;
		// 1+1
		for(ll j=1;j<=5;++j){
			// ll vs=v[j].size();
			// cout<<j<<" "<<vs<<endl;
			m.clear();
			for(ll i=0;i<v[j].size();++i){
				ll cur_num=add_digit(v[j][i]);
				++m[cur_num];
			}
			for(ll i=j;i<=9*j;++i){
				if(m[i]>=2){
					ans+=m[i]*(m[i]-1);
				}
			}	
		}
		cout<<ans<<endl;
		// 2+4
		m.clear();
		for(ll i=0;i<v[2].size();++i){
			ll cur_num=add_digit(v[2][i]);
			++m[cur_num];
		}
		for(ll i=0;i<v[4].size();++i){
			ll cur_num=add_digit(v[4][i]);
			ll fst_num=v[4][i][0]-'0';
			if(m[cur_num-fst_num*2]){
				ans+=m[cur_num-fst_num*2]*(m[cur_num-fst_num*2]+1);
			}
		}
		cout<<ans<<endl;
		// 1+3
		m.clear();
		for(ll i=0;i<v[1].size();++i){
			ll cur_num=add_digit(v[1][i]);
			++m[cur_num];
		}
		for(ll i=0;i<v[3].size();++i){
			ll cur_num=add_digit(v[3][i]);
			ll fst_num=v[3][i][0]-'0';
			if(m[cur_num-fst_num*2]){
				ans+=m[cur_num-fst_num*2]*(m[cur_num-fst_num*2]+1);
			}
		}
		cout<<ans<<endl;
		// 1+5
		m.clear();
		for(ll i=0;i<v[1].size();++i){
			ll cur_num=add_digit(v[1][i]);
			++m[cur_num];
		}
		for(ll i=0;i<v[5].size();++i){
			ll cur_num=add_digit(v[5][i]);
			string fst_str=v[5][i];
			ll fst_num=add_digit(fst_str.substr(0,2));
			if(m[cur_num-fst_num*2]){
				ans+=m[cur_num-fst_num*2]*(m[cur_num-fst_num*2]+1);
			}
		}
		cout<<ans<<endl;
		// 3+5
		m.clear();
		for(ll i=0;i<v[3].size();++i){
			ll cur_num=add_digit(v[3][i]);
			++m[cur_num];
		}
		for(ll i=0;i<v[5].size();++i){
			ll cur_num=add_digit(v[5][i]);
			ll fst_num=v[5][i][0]-'0';
			if(m[cur_num-fst_num*2]){
				ans+=m[cur_num-fst_num*2]*(m[cur_num-fst_num*2]+1);
			}
		}
		cout<<ans
	}
	
	return 0;
}