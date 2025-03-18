#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
#define ll long long
ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
ll lcm(ll a, ll b){
	return (a*b)/gcd(a,b);
}
int main() {
	// your code goes here
	int t=1;
	// cin>>t;
	while(t--){
		// n개의 박테리아, i번째 박테리아의 크기는 a[i]임
		// i번째 박테리아는 j번째 박테리아를 먹을 수 있음
		// a[i]>a[j] && a[i]<=a[j]+K
		// 1411
		//  0    1 2  3   4   5  6
		// [101,53,42,102,101,55,54]
		// 가장 최소로 남기면 몇 개의 박테리아가 남을 수 있는지?
		// [42,53,54,55,101,101,102]
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		ll ans=0;
		for(ll i=0;i<n;++i){
			ll L=i+1,R=n-1;
			ll x=v[i]+k;
			// x>=v[i] && v[i]<v[mid]
			bool flag=0;
			while(L<=R){
				ll mid=(L+R)/2;
				if(v[mid]==v[i]){
					L=mid+1;
					continue;
				}
				if(x<v[mid]){
					R=mid-1;
				}else{
					flag=1;
					break;
				}
			}
			if(flag) ++ans;
		}
		cout<<n-ans;
	} 
	return 0;
}