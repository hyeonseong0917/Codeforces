#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n,m,l;
		cin>>n>>m>>l;
		vector<pair<ll,ll>> h;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			h.push_back({a,b});
		}
		vector<pair<ll,ll>> v;
		for(ll i=0;i<m;++i){
			ll a,b;
			cin>>a>>b;
			v.push_back({a,b});
		}
		ll jp=1;
		ll idx=0;
		bool flag=0;
		priority_queue<ll> pq;
		ll ans=0;
		for(ll i=0;i<n;++i){
			ll L=h[i].first;
			ll R=h[i].second;
			ll diff=R-L+2;
			if(jp>=diff) continue;
			while(idx<m){
				if(v[idx].first>=L){
					break;
				}
				pq.push(v[idx].second);
				++idx;
			}
			while(!pq.empty() && jp<diff){
				jp+=pq.top();
				++ans;
				pq.pop();
			}
			if(jp<diff){
				flag=1;
				break;
			}
		}

		if(flag){
			cout<<-1<<"\n";
		}else{
			cout<<ans<<"\n";
		}
		
	}
	return 0;
}