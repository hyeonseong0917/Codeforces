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
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		map<ll,ll> last_idx;
		vector<ll> unique_num;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			if(i==0){
				unique_num.push_back(v[i]);
			}else{
				if(!last_idx[v[i]]){
					unique_num.push_back(v[i]);
				}
			}
			last_idx[v[i]]=i;
		}
		sort(unique_num.begin(),unique_num.end());
		priority_queue<ll> pq;
		ll idx=0;
		vector<ll> ans;
		for(ll i=0;i<unique_num.size();++i){
			ll cur_num=unique_num[i];
			ll cur_idx=last_idx[cur_num];
			if(!pq.empty() && cur_num>pq.top()*-1){
				while(idx<=cur_idx){
					pq.push((v[idx]+1)*-1);
					++idx;
				}
				continue;
			}
			while(idx<=cur_idx){
				if(cur_num==v[idx]){
					ans.push_back(cur_num);
				}else{
					pq.push((v[idx]+1)*-1);
				}
				++idx;
			}
		}
		while(!pq.empty()){
			ll cur_num=pq.top()*-1;
			pq.pop();
			ans.push_back(cur_num);
		}
		for(ll i=0;i<n;++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";
		// [3,1,3,4,1,2,3,4,1,6,8,7,3,4,2]
		// 초기에 가장 작은 수 1
		// [1,1,1]
		
		// [3,1,3,4,1,2]
		// [1,1,2,4,4,5]
		// 각 수의 가장 마지막 인덱스를 매핑하기
		// 가장 작은 수, 가장 작은 인덱스부터 마지막 인덱스까지
		// 같은 수 있다면 ans에 넣고 아니면 pq에 +1해서 넣기
		

		
	} 
	return 0;
}