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
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		vector<ll> p;
		p.push_back(v[0]);
		ll L=1;
		bool flag=0;
		while(L<n){
			ll ps=p.size();
			if(v[L]!=p[ps-1]){
				flag=1;
				break;
			}
			// v[L]==p[ps-1]
			++L;
			if(L>=n){
				break;
			}
			for(ll i=L;i<n;++i){
				if(v[i]==p[ps-1]){
					++v[i];
				}
			}
			p.push_back(v[L]);
			++L;
		}
		if(flag){
			cout<<"NO"<<"\n";
		}else{
			cout<<"YES"<<"\n";
		}
	} 
	return 0;
}