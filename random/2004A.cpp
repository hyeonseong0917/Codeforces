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
		// A와 B는 n개의 아이템 갖고있음 쪼개고싶음?
		// i번째 아이템의 비용은 a[i]임
		// 각 턴마다 남은 아이테 중 하나를 가져감
		// 아이템이 남지 않으면 종료
		// 최종점수: A-B
		// A는 점수를 ㅚ대로, B는 최소로
		// B는 a[i] 아무 정수값이나 증가시킬 수 있음
		// 전체 증가량은 k보다 작거나 같아야 함
		// B가 조정함으로써 얻을 수 있는 최종 점수의 최솟값은?
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		// A는 최댓값을 가져갈거고, B도 최댓값을 가져가야함
		// 이웃한 수의 diff을 최소로 만들어야함
		// 이웃한 수의 diff을 큰 순으로 봐야되나?
		ll cur_sum=0;
		vector<pair<ll,ll>> p;
		// A는 무조건 큰 수를 가져가려고 하지 않을까?
		for(ll i=n-2;i>=0;i-=2){
			ll cur_diff=min(v[i+1]-v[i],k);
			v[i]+=cur_diff;
			k-=cur_diff;
		}
		ll cnt=0;
		ll A=0, B=0;
		for(ll i=n-1;i>=0;--i){
			if(cnt%2==0){
				A+=v[i];
			}else{
				B+=v[i];
			}
			++cnt;
		}
		cout<<A-B<<"\n";

	} 	

	return 0;
}