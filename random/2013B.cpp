#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		// sort(v.begin(),v.end());
		// 마지막 남은 선수의 레이팅이 가장 크도록 하고싶음
		// i<j이면 j가 이긴다. 뒤에있는게 더 쎔
		// 1 2 3 4 5
		// 1 2 0 1 5
		// 1 0 0 -1 5
		ll sum=0;
		for(ll i=0;i<=n-3;++i){
			sum+=v[i];
		}
		ll c=v[n-2]-sum;
		cout<<v[n-1]-c<<"\n";
	} 
	return 0;
}