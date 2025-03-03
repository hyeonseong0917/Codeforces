#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;

#define ll long long
ll mod=998244353;
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		// 0,1,2,..n의 포인트들이 있음
		// 텔레포트들이 1,2,3,..n에 있음
		// 포인트 i에서 다음과 같이 할 수 있음
		// 왼쪽 오른쪽 한칸: 1원
		// i에서 텔레포트 쓰면 a[i]원 쓰게됨. 결과적으로
		// 0으로 감. 한 번 썼으면 다시 못씀
		// c코인이 있다면 최대 몇 개의 텔레포트 사용 가능?
		ll n,c;
		cin>>n>>c;
		priority_queue<ll> pq;
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			pq.push((a+i+1)*-1);
		}
		ll ans=0;
		while(!pq.empty()){
			ll cur_num=pq.top()*-1;
			pq.pop();
			if(c-cur_num>=0){
				++ans;
			}else{
				break;
			}
			c-=cur_num;
		}
		cout<<ans<<"\n";
		// 5 9
		// 0 1 2 3 4
		// 2 3 1 4 1
		// 3 5 4 8 6 (진짜 써야되는 값)
		

		// 바로 앞에 있는거 먹는게 이득인가?
	} 
	return 0;
}