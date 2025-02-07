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
	// cin>>t;
	while(t--){
		// b d
		// y: 가장 많은 사람이 살았던 연도
		// k: 그 때 살고 있더 사람
		ll n;
		cin>>n;
		vector<pair<ll,ll>> v;
		ll max_num=-1;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			v.push_back({a,b});
		}
		sort(v.begin(),v.end());
		priority_queue<ll> pq;
		ll y=v[0].first;
		ll k=1;
		pq.push(v[0].second*-1);
		for(ll i=1;i<n;++i){
			ll cur_start=v[i].first;
			while(!pq.empty()){
				ll cur_num=pq.top()*-1;
				if(cur_num<=cur_start){
					pq.pop();
				}else{
					break;
				}
			}
			ll ps=0;
			if(!pq.empty()){
				ps=pq.size();
			}
			if(k<ps+1){
				k=ps+1;
				y=cur_start;
			}
			pq.push(v[i].second*-1);
		}
		cout<<y<<" "<<k<<"\n";
	} 

	return 0;
}