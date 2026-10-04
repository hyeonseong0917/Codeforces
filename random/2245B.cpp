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
		// 1700
		// n개의 정수로 구성된 배열 a가있음
		// 수열이 empty할때까지 다음 두가지 연산을 몇 번이나 할 수 있음
		// 1. 원소 하나를 점수에 더하고, 삭제함
		// 2. 두 개의 인접한 원소를 선택하고, 최대 점수를 더하고, 두 개를 삭제함
		// c: 한 번 연산을 할 때의 비용
		// 최대 점수를 구해라
		ll n,c;
		cin>>n>>c;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		if(n==1){
			cout<<v[0]-c<<"\n";
			continue;
		}
		sort(v.rbegin(),v.rend());
		ll min_cnt=(n+1)/2;
		ll max_cnt=n;
		ll max_num=0;
		for(ll i=0;i<n;++i){
			max_num+=v[i]-c;
		}
		ll idx=min_cnt-1;
		ll sum=0;
		for(ll i=0;i<idx;++i){
			sum+=v[i]-c;
		}
		while(idx<n){
			sum+=v[idx]-c;
			max_num=max(max_num,sum);
			++idx;
		}
		cout<<max_num<<"\n";
	} 	

	return 0;
}