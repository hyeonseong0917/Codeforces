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
		// a를 좋은 배열로 ㅏㄴ들어야함
		// i,j에 대해 다음 조건 만족
		// 1<=i,j<=m
		// 모든 i,j에 대해해
		// max(b[i],b[j])가 min(b[i],b[j])
		// 연산 최대 n번 수행
		// 1. 인덱스 i선택
		// 2. 정수 x선택 (0<=x<=a[i])
		// 3. a[i]+=x
		// 4. a[i]<=10^18
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		ll max_num=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		vector<pair<ll,ll>> p;
		for(ll i=0;i<n;++i){
			if(v[i]==1) continue;
			// 2의 제곱으로 만들기
			ll c=2;
			while(1){
				if(c>=v[i]){
					p.push_back({i+1,c-v[i]});
					break;
				}
				c*=2;
			}
		}
		ll ps=p.size();
		cout<<ps<<"\n";
		for(ll i=0;i<ps;++i){
			cout<<p[i].first<<" "<<p[i].second<<"\n";
		}


	} 

	return 0;
}