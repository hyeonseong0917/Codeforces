#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		// 1334
		// 0에서 n까지 고유한 숫자들 n개가 주어짐
		// a[i]를 전체 수의 MEX로 교체??

		// [0,1,3]
		// [2,1,3]
		// [2,0,3]
		// [2,0,1]

		// 처음 MEX를 구한다
		// a[i]가 MEX보다 작다면

		// 1 2 3 4 5
		// 0 1 2 3 4
		// 1 0 2 3 4
		// 0 1 2 3 4
		// 1
		ll n,k;
		cin>>n>>k;
		k%=(n+1);
		deque<ll> dq;
		ll MEX;
		vector<ll> check(n+1,0);
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			++check[a];
			dq.push_back(a);
		}
		for(ll i=0;i<=n;++i){
			if(!check[i]){
				MEX=i;
				break;
			}
		}
		for(ll i=0;i<k;++i){
			dq.push_front(MEX);
			MEX=dq.back();
			dq.pop_back();
		}
		while(!dq.empty()){
			cout<<dq.front()<<" ";
			dq.pop_front();
		}cout<<"\n";
	}
	return 0;
}