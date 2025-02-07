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
	//1102
	while(t--){
		// p: 길이 n인 permutation
		// 서브시퀀스 s1,s2..sk는 최소 길이가 2다
		// abs(s1-s2)+abs(s2-s3)+...+abs(sk-1 - sk)가 최대로
		// 길이 k가 최소가 되도록

		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}

		// 3 2 1
		// 최댓값: [3,1] 혹은 [3,2,1]
		// 길이가 최소여야하므로 [3,1]선택

		// 0 1 2 3
		// 1 3 4 2
		// i번쨰 요소를 서브시퀀스에 넣을 것인지 어떻게 판단?
		// i번째 요소를 서브시퀀스에 넣는다면 
		// 그 다음 가장 차이가 큰 값 가져가야함

		// 0 1 2 3
		// 1 8 9 10 4 3 2 5 6 7
		// 7+1+1+6+1+1+3+1+1=22
		// [1,8,9,10]
		// [4,3,2]
		// [5,6,7]
		// [1,10,4,2,5,7]

		// 10 8 9 1 4 3 2 5 6 7
		// 2+1+8+3+1+1+3+1+1=21
		// [10,8]
		// [8,9]
		// [9,1]
		// [1,4]
		// [4,2]
		// [2,7]
		// [9,1]
		// [4,3,2]
		// [5,6,7]
		// [10,8,9,1,4,2,5,7]

		// 같은 증감 구간끼리 묶기
		vector<pair<ll,ll>> p;
		ll cur_num=v[0];
		ll L=0, R=1;
		bool is_plus=1;
		if(cur_num>v[1]){
			is_plus=0;
		}
		// 6 5 4 7
		// 6 5 8 9 2
		for(ll i=1;i<n;++i){
			if(is_plus){
				if(v[i]>v[i-1]){
					R=i;
				}else{
					// v[i]<v[i-1]
					p.push_back({L,R});
					L=R;
					R=i;
					is_plus=0;
				}
			}else{
				if(v[i]<v[i-1]){
					R=i;
				}else{
					// v[i]>v[i-1]
					p.push_back({L,R});
					L=R;
					R=i;
					is_plus=1;
				}
			}
		}
		p.push_back({L,R});
		// for(ll i=0;i<p.size();++i){
		// 	cout<<p[i].first<<" "<<p[i].second<<"\n";
		// }
		vector<ll> ans;
		ans.push_back(v[p[0].first]);
		ans.push_back(v[p[0].second]);
		for(ll i=1;i<p.size();++i){
			ans.push_back(v[p[i].second]);
		}
		ll as=ans.size();
		cout<<as<<"\n";
		for(ll i=0;i<ans.size();++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";
	} 

	return 0;
}