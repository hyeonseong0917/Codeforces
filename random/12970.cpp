#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long

bool comp(pair<ll,ll> a, pair<ll,ll> b){
	if(a.first==b.first){
		return a.second<b.second;
	}
	return a.first<b.first;
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	ll t=1;
	while(t--){
		ll n;
		cin>>n;
		vector<pair<ll,ll>> v;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			v.push_back({a,b});
		}
		sort(v.begin(),v.end(),comp);
		priority_queue<ll> pq;
		ll ans=1;
		for(ll i=0;i<n;++i){
			if(pq.empty()){
				pq.push(v[i].second*-1);
			}else{
				while(!pq.empty()){
					ll cur_num=pq.top()*-1;
					if(cur_num<=v[i].first){
						pq.pop();
					}else{
						pq.push(v[i].second*-1);
						break;
					}
				}
				if(pq.empty()){
					pq.push(v[i].second*-1);
				}
				ll ps=pq.size();
				ans=max(ans,ps);
			}
		}
		cout<<ans;
	}
	return 0;
}