#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		ll n=s.size();
		vector<ll> v;
		for(ll i=0;i<n;++i){
			v.push_back(s[i]-'0');
		}
		vector<ll> dp(n,0);
		dp[n-1]=n-1;
		for(ll i=n-2;i>=0;--i){
			if(v[i]<=v[dp[i+1]]){
				dp[i]=i;
			}else{
				// v[i]>v[dp[i+1]]
				dp[i]=dp[i+1];
			}
		}
		priority_queue<ll> pq;
		vector<ll> ans;
		ll idx=0;
		while(idx<n){
			if(pq.empty() && dp[idx]==idx){
				ans.push_back(v[idx]);
				++idx;
				continue;
			}
			ll R=dp[idx];
			if(pq.empty()){
				for(ll i=idx;i<R;++i){
					pq.push(v[i]*-1);
				}
				ans.push_back(v[R]);
				idx=R+1;
			}else{
				// idx번째 값과 pq의 top()*-1을 비교?
				ll cur_num=v[R]; // idx이후 최솟값
				ll q_num=min(9ll,pq.top()*-1+1);
				if(cur_num<=q_num){
					for(ll i=idx;i<R;++i){
						pq.push(v[i]*-1);
					}
					ans.push_back(v[R]);
					idx=R+1;
				}else{
					ans.push_back(q_num);
					pq.pop();
					
				}
				
			}
		}
		while(!pq.empty()){
			ans.push_back(min(9ll,pq.top()*-1+1));
			pq.pop();
		}
		for(ll i=0;i<n;++i){
			cout<<ans[i];
		}cout<<"\n";
	} 
	return 0;
}