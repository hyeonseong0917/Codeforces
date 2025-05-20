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
		// 1159
		// n개의 숫자들이 있는 가방 첫번째
		// 두 번째 가방은 비었음
		// 1. 1번째 가방의 숫자를 두번째 가방으로 옮기거나.
		// 2. 1번째 가방에서 두번째 가방에도 있는 숫자를 선택해서 +1
		// 두 가방을 동일하게 만들 수 있는지??
		// +1은 첫 번째 가방에서만 가능하니까, 큰 거를 두 번째 가방으로 옮겨야?
		// n<=1000
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> check(n+1);
		for(ll i=0;i<n;++i){
			cin>>v[i];
			++check[v[i]];
		}
		// [3,3,3,3,4,4,4,5,6,6,7],[]

		// [4,5,5,6]
		// [3,3,3,3,4,5]
		// [3,3,3,4,4,5]
		// [3,3,3,4,5,5]
		// [3,3,4,4,5,5]
		bool flag=0;
		for(ll i=1;i<n;++i){
			if(!check[i]) continue;
			if(check[i]==1){
				flag=1;
				break;
			}
			ll diff=check[i]-2;
			check[i]-=diff;
			check[i+1]+=diff;
		}	
		for(ll i=1;i<=n;++i){
			if(check[i]%2==1){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<"NO"<<"\n";
		}else{
			cout<<"YES"<<"\n";
		}
	} 
	return 0;
}