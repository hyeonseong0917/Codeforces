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
		ll n,l,r;
		cin>>n>>l>>r;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		--l;
		--r;
		// 1. [0,l-1]에서 [l,r]의 큰 수들 몇 개 상쇄시킬 수 있는지?
		priority_queue<ll> m_pq, l_pq, r_pq;
		for(ll i=l;i<=r;++i){
			m_pq.push(v[i]);
		}
		for(ll i=0;i<l;++i){
			l_pq.push(v[i]*-1);
		}
		ll ans=0;
		while(!m_pq.empty() && !l_pq.empty()){
			ll m_top=m_pq.top();
			ll l_top=l_pq.top()*-1;
			if(l_top<m_top){
				m_pq.pop();
				m_pq.push(l_top);
				l_pq.pop();
			}else{
				break;
			}
		}
		while(!m_pq.empty()){
			ans+=m_pq.top();
			m_pq.pop();
		}
		for(ll i=l;i<=r;++i){
			m_pq.push(v[i]);
		}
		for(ll i=r+1;i<n;++i){
			r_pq.push(v[i]*-1);
		}
		while(!m_pq.empty() && !r_pq.empty()){
			ll m_top=m_pq.top();
			ll r_top=r_pq.top()*-1;
			if(r_top<m_top){
				m_pq.pop();
				m_pq.push(r_top);
				r_pq.pop();
			}else{
				break;
			}
		}
		ll sed_ans=0;
		while(!m_pq.empty()){
			sed_ans+=m_pq.top();
			m_pq.pop();
		}
		ans=min(ans,sed_ans);
		cout<<ans<<"\n";
	} 
	return 0;
}
