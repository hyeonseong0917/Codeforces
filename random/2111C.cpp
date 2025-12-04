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
		// i이전 값들을 v[i]로 바꿈 -> 비용은 (i-1)*a[i]
		// i이후 값들을 v[i]로 바꿈 -> 비용은 (n-i)*a[i]
		// 모든 원소들을 같게 만들기 위한 최솟값?
		ll ans=250000000000+1;
		ll L=0, R=0;
		while(L<=R && R<n){
			if(v[L]!=v[R]){
				++L;
			}else{
				ans=min(ans,v[L]*L+v[L]*(n-R-1));
				++R;
			}
		}
		cout<<ans<<"\n";
	} 	

	return 0;
}