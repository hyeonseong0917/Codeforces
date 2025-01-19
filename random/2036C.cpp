#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		ll q;
		cin>>q;
		vector<pair<ll,char>> v;
		for(ll i=0;i<q;++i){
			ll a;
			cin>>a;
			char b;
			cin>>b;
			v.push_back({a,b});
		}
		ll ss=s.size();
		if(ss<=3){
			for(ll i=0;i<q;++i){
				cout<<"NO"<<"\n";
			}
			continue;
		}
		// 1100의 cnt 개수 세기
		ll cnt=0;
		for(ll i=0;i<=ss-4;++i){
			string cur_str=s.substr(i,4);
			if(cur_str.compare("1100")==0){
				++cnt;
			}
		}
		for(ll i=0;i<q;++i){
			ll idx=v[i].first-1;
			char c=v[i].second;
			// idx겹치는 구간이 1100인지 아닌지?
			bool is_pattern=0;
			for(ll j=idx-3;j<=idx;++j){
				if(j<0) continue;
				string cur_str=s.substr(j,4);
				if(cur_str.compare("1100")==0){
					is_pattern=1;
					break;
				}
			}
			if(is_pattern){
				s[idx]=c;
				is_pattern=0;
				for(ll j=idx-3;j<=idx;++j){
					if(j<0) continue;
					string cur_str=s.substr(j,4);
					if(cur_str.compare("1100")==0){
						is_pattern=1;
						break;
					}
				}	
				if(!is_pattern){
					--cnt;
				}
			}else{
				s[idx]=c;
				is_pattern=0;
				for(ll j=idx-3;j<=idx;++j){
					if(j<0) continue;
					string cur_str=s.substr(j,4);
					if(cur_str.compare("1100")==0){
						is_pattern=1;
						break;
					}
				}	
				if(is_pattern){
					++cnt;
				}
			}
			if(cnt>=1){
				cout<<"YES"<<"\n";
			}else{
				cout<<"NO"<<"\n";
			}
		}
	} 
	return 0;
}