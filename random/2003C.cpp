#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long
#define pb push_back

bool comp(pair<ll,ll> a, pair<ll,ll> b){
	return a.second>b.second;
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	cin>>t;
	while(t--){	
		// string s
		// i<=k<j에서 k가 존재한다면
		// ppair: s[k]!=s[k+1] && (s[k]!=s[i] || s[k+1]!=s[j])
		// i,j가 good pair일 조건은 s[i]=s[j]이거나, (i,j)가 ppair

		// #s를 reorder해서 good pair 수를 최대로 하고싶음#
		ll n;
		cin>>n;
		string s;
		cin>>s;
		if(n==1){
			cout<<s<<"\n";
			continue;
		}
		// abc
		// 중복인 알파벳들은 무조건 good pair 만들 수 있음
		// turtle
		// turlet
		// [i,j] k
		vector<ll> cnt(26,0);
		for(ll i=0;i<n;++i){
			++cnt[s[i]-'a'];
		}
		vector<pair<ll,ll>> v;
		for(ll i=0;i<26;++i){
			if(!cnt[i]) continue;
			v.push_back({i,cnt[i]});
		}
		ll vs=v.size();
		if(vs==1){
			cout<<s<<"\n";
			continue;
		}
		sort(v.begin(),v.end(),comp);
		queue<pair<ll,ll>> q;
		ll diff=v[0].second-v[1].second;
		for(ll i=0;i<diff;++i){
			char c='a'+v[0].first;
			cout<<c;
		}
		v[0].second=v[1].second;
		for(ll i=0;i<v.size();++i){
			q.push(v[i]);
		}
		while(!q.empty()){
			char c='a'+q.front().first;
			ll idx=q.front().first;
			ll cnt=q.front().second;
			q.pop();
			if(cnt==0) continue;
			cout<<c;
			q.push({idx,cnt-1});
		}
		cout<<"\n";
	}
	return 0;
}