#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long

ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}

int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		// 100개의 방.. 그 사이에 99개의 문
		// i번째 문은 i번째 방과 i+1번째 방으로 연결
		// 문은 잠기거나 안잠겼을 수 있음
		// 처음에 다 안잠겨있음
		// x는 y로부터 도달 가능하다 언제? 그 사이 문들이 모두 안잠겨있으면
		// A는 [l,r]의 몇 방에 있다
		// B는 [L,R]의 몇 방에 있다
		// 서로 다른 방
		// A와 B가 어디서 시작하든, 서로 만나게 하지 못하도록
		// 잠궈야 하는 방의 최소 개수는?
		ll l,r,L,R;
		cin>>l>>r;
		cin>>L>>R;
		// 1 2
		// 3 4
		// 1. segment가 아예 안겹치면 한 개만 잠구기
		ll cnt=r-l+1+R-L+1;
		vector<ll> check(100+1);
		for(ll i=l;i<=r;++i){
			++check[i];
		}
		for(ll i=L;i<=R;++i){
			++check[i];
		}
		ll c=0;
		for(ll i=1;i<=100;++i){	
			if(check[i]){
				++c;
			}
		}
		if(c==cnt){
			cout<<1<<"\n";
			continue;
		}
		// 3 7
		// 6 7

		// 2. segment가 겹치긴함
		// (3) 4 (4) 5 (5)

		// (6) 7 (7) 8 (8) 9 (9) 10 (10)
		// 2 8

		// 2 10
		// 4 8
		// (1) 2 (2) 3 (3) 4 (4) 5 (5) 6 (6) 7 (7) 8 (8)

		// 2. 작은 구간 기준으로
		// (1) R다르다면 R 작은거 막기 +1
		// (1)-1 R같다면..
		// (2) (L 다르다면 ) L기준 큰거 막기 +1 (L-1)
		// (3) L과 R사이의
		ll ans=0;
		if(R!=r){
			++ans;
		}
		if(L!=l){
			++ans;
		}
		R=min(R,r);
		L=max(L,l);
		ans+=R-L;
		cout<<ans<<"\n";
	} 	

	return 0;
}