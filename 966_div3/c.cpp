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
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		ll m;
		cin>>m;
		for(ll i=0;i<m;++i){
			string s;
			cin>>s;
			ll ss=s.size();
			if(ss!=n){
				cout<<"NO"<<"\n";
				continue;
			}
			vector<ll> g[26];
			for(ll j=0;j<s.size();++j){
				g[s[j]-'a'].push_back(j);
			}
			vector<ll> check(n,0);
			map<ll,ll> M;
			bool flag=1;
			for(ll j=0;j<26;++j){
				if(g[j].empty()) continue;
				if(!flag) break;
				if(g[j].size()>=2){
					ll cur_num=v[g[j][0]];
					if(M[cur_num]){
						flag=0;
						break;
					}
					check[g[j][0]]=1;
					for(ll k=1;k<g[j].size();++k){
						if(cur_num==v[g[j][k]]){
							check[g[j][k]]=1;
						}else{
							flag=0;
							break;
						}
					}
					++M[cur_num];
				}
			}
			for(ll j=0;j<v.size();++j){
				if(check[j]) continue;
				if(M[v[j]]){
					flag=0;
					break;
				}else{
					++M[v[j]];
				}
			}
			if(!flag){
				cout<<"NO"<<"\n";
			}else{
				cout<<"YES"<<"\n";
			}
		}
	}
	return 0;
}