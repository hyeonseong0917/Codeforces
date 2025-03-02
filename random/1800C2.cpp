#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		// 1310
		// n개의 카드로 이루어진 덱이 있음
		// 각자의 파워가 있음
		// 두 가지 타입의 카드가 존재
		// 히어로 카드: 해당 카드의 파워는 항상 0
		// 보너스 카드: 해당 카드는 항상 ㅑㅇ수

		// 덱의 가장 위에서 카드 뽑음
		// 보너스 카드였다면 내 보너스 덱 위에 놓거나 버리기 가능
		// 히어로 카드였다면 내 보너스 덱 위에 있는 파워만큼 더해짐
		ll ans=0;
		priority_queue<ll> pq;
		ll n;
		cin>>n;
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			if(a==0){
				if(!pq.empty()){
					ans+=pq.top();
					pq.pop();
				}
			}else{
				pq.push(a);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}