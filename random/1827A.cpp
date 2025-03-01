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
		vector<ll> a(n,0), b(n,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		for(ll i=0;i<n;++i){
			cin>>b[i];
		}
		ll mod=1000000007;
		// a는 pairwise
		// a를 재배열해서 모든 i에 대해 a[i]>b[i]가 되도록 하는
		// 모든 경우의 수를 구하여라라

		// b: 1 1 3 4 5 6
		// a: 2 4 5 6 8 9
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		ll ans=1;
		ll cnt=0;
		for(ll i=n-1;i>=0;--i){
			ll L=0, R=n-1;
			ll idx=2023101800;
			while(L<=R){
				ll mid=(L+R)/2;
				if(a[mid]>b[i]){
					idx=min(idx,mid);
					R=mid-1;
				}else{
					L=mid+1;
				}
			}
			if(idx==2023101800){
				ans=0;
				break;
			}
			ans*=(n-idx-cnt);
			ans%=mod;
			++cnt;
		}
		cout<<ans<<"\n";
	} 
	return 0;
}