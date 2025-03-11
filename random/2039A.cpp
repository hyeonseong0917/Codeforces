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
		// 1100
		// n
		// 1<=a1<a2<an<=100 a[i]%i와 a[j]%j가 다를때
		// 모든 페어에 대해
		ll n;
		cin>>n;
		// n<=50, 1<=a[i]<=100
		// 1 2 3 4
		// 2 3 5 7
		vector<ll> ans(n,0);
		ans[0]=2;
		for(ll i=1;i<n;++i){
			ans[i]=(i+1)+i;
		}
		for(ll i=0;i<n;++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";
	} 
	return 0;
}