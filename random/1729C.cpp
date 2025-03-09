#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long
bool comp(pair<ll,ll> a, pair<ll,ll> b){
	if(a.first==b.first){
		return a.second<b.second;
	}
	return a.first>b.first;
}
int main() {
	// your code goes here
	int o=1;
	cin>>o;
	while(o--){
		string s;
		cin>>s;
		if(s[0]==s[s.size()-1]){
			ll cnt=1;
			vector<ll> v;
			v.push_back(0);
			for(ll i=1;i<s.size();++i){
				if(s[i]==s[0]){
					++cnt;
					v.push_back(i);
				}
			}
			cout<<0<<" "<<cnt<<"\n";
			for(ll i=0;i<v.size();++i){
				cout<<v[i]+1<<" ";
			}cout<<"\n";

			continue;
		}
		ll cost=abs(s[0]-s[s.size()-1]);
		ll cnt=0;
		vector<ll> p;
		if(s[0]>s[s.size()-1]){
			ll cur_val=s[0]-'a';
			ll last_val=s[s.size()-1]-'a';
			vector<pair<ll,ll>>	 v;
			for(ll i=0;i<s.size();++i){
				v.push_back({s[i]-'a',i});
			}
			sort(v.begin(),v.end(),comp);
			
			
			for(ll i=0;i<v.size();++i){
				if(v[i].first>cur_val) continue;
				if(v[i].first<last_val) break;
				++cnt;
				p.push_back(v[i].second);
			}
		}else{
			ll cur_val=s[0]-'a';
			ll last_val=s[s.size()-1]-'a';
			vector<pair<ll,ll>>	 v;
			for(ll i=0;i<s.size();++i){
				v.push_back({s[i]-'a',i});
			}
			sort(v.begin(),v.end());
			for(ll i=0;i<v.size();++i){
				if(v[i].first<cur_val) continue;
				if(v[i].first>last_val) break;
				++cnt;
				p.push_back(v[i].second);
			}
		}
		cout<<cost<<" "<<cnt<<"\n";
		for(ll i=0;i<p.size();++i){
			cout<<p[i]+1<<" ";
		}cout<<"\n";
		

	} 
	return 0;
}