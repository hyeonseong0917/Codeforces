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
		// 1446
		// knapsack capacity: "W"
		// n개의 item, i번째 무게는 w[i]
		// 전체 무게의 합 C가 최소 W의 절반 이상이 되도록
		// (w+1)/2 <= C <= W

		// n,w
		ll n,w;
		cin>>n>>w;
		vector<pair<ll,ll>> v;
		vector<ll> psum(n,0);
		ll sum=0;
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			v.push_back({a,i});
			sum+=a;
		}
		sort(v.begin(),v.end());
		psum[0]=v[0].first;
		for(ll i=1;i<n;++i){
			psum[i]=psum[i-1]+v[i].first;
		}
		// 불가능한 경우도 있을까??
		// 1. 전체 합이 (w+1)/2보다 작다면
		if(sum<(w+1)/2){
			cout<<-1<<"\n";
			continue;
		}
		// 3 20
		// 1 1 20
		// 3 4 15 18
		//        9
		// 마지막 수가(w+1)/2보다 작았다면, 첫 수도 무조건 작을것
		// 그렇기 때문에 해당 구간에 못들어갔다가, 초과하는 경우는 없음
		// 가장 큰 수부터
		ll L=0, R=n-1;
		sum=0;
		vector<ll> ans;
		while(L<=R){
			// R가능한지??
			ll tmp=sum+v[R].first;
			if(tmp>w){
				--R;
			}else{
				// tmp<=w
				sum+=v[R].first;
				ans.push_back(v[R].second+1);
				--R;
				if(sum>=(w+1)/2 && sum<=w){
					break;
				}
			}
		}
		if(sum>=(w+1)/2 && sum<=w){
			ll as=ans.size();
			cout<<as<<"\n";
			for(ll i=0;i<ans.size();++i){
				cout<<ans[i]<<" ";
			}
		}else{
			cout<<-1;
		}cout<<"\n";
	} 

	return 0;
}