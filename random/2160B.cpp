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
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		// f(v): v배열의 고유한 원소의 개수
		// b[i]: f(a[1:i])+f(a[2:i])+f(a[3:i])...f(a[i:i])
		vector<ll> ans(1,1);
		ll cnt=2;
		for(ll i=1;i<n;++i){
			// v[i]에 대해 i번째에서는 고유한 원소를 추가할지? 있는 원소를 추가할지?
			// 있는 원소라면 언제부터 있는 원소를 추가할지??
			ll diff=v[i]-v[i-1];
			if(diff-1==i){
				ans.push_back(cnt++);
			}else{
				// 새 원소는 아님
				ans.push_back(ans[i-diff]);
			}
		}
		for(ll i=0;i<n;++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";

	} 

	return 0;
}