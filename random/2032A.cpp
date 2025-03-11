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
	int o=1;
	cin>>o;
	while(o--){
		// 1105
		// n개의 전구, 2n개의 스위치
		// 각 전구는 정확히 2개의 스위치
		// 각 스위치는 정확히 한 개의 전구에 연결
		// 스위치를 토글하면 스위치와 연결된 전구도 토글
		// 기본 상태: 모든 전구는 off상태임

		// 2n개의 스위치 상태가 주어짐
		// 전구의 최소/최대 on개수를 구하라

		// 0 0 0 zuwudlTdj
		// 0 1 1 1 0 0
		// 0 0 0 0 1 1 1
		// 0 0 0 1 1 1
		// 0 0 0 1 1 1 1
		ll n;
		cin>>n;
		vector<ll> v(2*n,0);
		ll one_cnt=0;
		ll zero_cnt=0;
		for(ll i=0;i<n*2;++i){
			cin>>v[i];
			if(v[i]==0){
				++zero_cnt;
			}else{
				++one_cnt;
			}
		}

		cout<<zero_cnt%2<<" "<<min(one_cnt,zero_cnt)<<"\n";
	} 
	return 0;
}