#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		// [5,4,2,1,3]
		// [1,2,3]
		// [3,1,2]
		ll n;
		cin>>n;
		deque<ll> dq;
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			dq.push_back(a);
		}
		vector<ll> ans;
		for(ll i=n;i>=1;--i){
			ll cnt=0;
			queue<ll> q;
			while(1){
				ll cur_num=dq.front();
				dq.pop_front();
				++cnt;
				if(cur_num==i){
					break;
				}
				q.push(cur_num);
			}
			if(cnt==i){
				cnt=0;
			}
			ans.push_back(cnt);
			while(!q.empty()){
				ll cur_num=q.front();
				q.pop();
				dq.push_back(cur_num);
			}
		}
		for(ll i=n-1;i>=0;--i){
			cout<<ans[i]<<" ";
		}cout<<"\n";
		

	} 	

	return 0;
}