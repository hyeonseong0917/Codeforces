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
		ll n,m;
		cin>>n>>m;
		vector<ll> v(n,0);
		vector<ll> x(m,0);
		vector<ll> even_vec;
		vector<ll> odd_vec;
		ll total_sum=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			total_sum+=v[i];
			if(i%2==0){
				even_vec.push_back(v[i]);
			}else{
				odd_vec.push_back(v[i]);
			}
		}
		sort(even_vec.rbegin(),even_vec.rend());
		sort(odd_vec.rbegin(),odd_vec.rend());
		ll sum=0;
		for(ll i=0;i<m;++i){
			cin>>x[i];
			--x[i];
		}
		ll even_idx=0;
		ll odd_idx=0;
		ll e_len=even_vec.size();
		ll o_len=odd_vec.size();
		for(ll i=0;i<m;++i){
			// x[i]에서 짝수 인덱스 차이를 가지는 값들만 mark할 수 있음
			// x[i]가 홀수라면, 홀수 인덱스의 값들만
			// x[i]가 짝수라면, 짝수 인덱스의 값들만
			if(x[i]%2==0){
				if(even_idx==e_len) continue;
				if(even_vec[even_idx]<0 && even_idx>0) continue;
				sum+=even_vec[even_idx++];
			}else{
				if(odd_idx==o_len) continue;
				if(odd_vec[odd_idx]<0 && odd_idx>0) continue;
				sum+=odd_vec[odd_idx++];
			}
		}
		cout<<total_sum-sum<<"\n";
	} 	

	return 0;
}