#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
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
		bool is_exist_one=0;
		bool flag=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			if(v[i]==1){
				is_exist_one=1;
			}
		}
		if(n==1){
			cout<<0<<"\n";
			continue;
		}
		for(ll i=0;i<n;++i){
			if(v[i]!=1 && is_exist_one){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<-1<<"\n";
			continue;
		}
		bool is_all_same=0;
		vector<pair<ll,ll>> ans;
		while(1){
			is_all_same=1;
			for(ll i=1;i<n;++i){
				if(v[0]!=v[i]){
					is_all_same=0;
					break;
				}
			}
			if(is_all_same) break;
			ll min_num=2023101800;
			ll min_idx=-1;
			for(ll i=0;i<n;++i){
				if(v[i]<min_num){
					min_num=v[i];
					min_idx=i;
				}
			}
			// min_num에 대해 나머지 숫자들 정상화
			for(ll i=0;i<n;++i){
				if(i==min_idx || v[i]==min_num) continue;
				// v[i]를 min_num으로 나눈 값 넣기
				v[i]=(v[i]+min_num-1)/min_num;
				ans.push_back({i+1,min_idx+1});
			}
		}
		ll as=ans.size();
		cout<<as<<"\n";
		for(ll i=0;i<ans.size();++i){
			cout<<ans[i].first<<" "<<ans[i].second<<"\n";
		}
	} 
	return 0;
}