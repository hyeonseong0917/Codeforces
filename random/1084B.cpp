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
		// 1444
		// n개의 케이그?
		// i번째 케이그에는 v[i]리터가 있음
		// s리터를 마시고자함
		// 최소한으로 남은 통의 양을 최대화 시키는 것
		ll n,s;
		cin>>n>>s;
		vector<ll> v(n,0);
		ll sum=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			sum+=v[i];
		}
		if(sum<s){
			cout<<-1;
			break;
		}
		// 가장 최소로 남은 v[i]가 최대가 되도록
		// 
		sort(v.begin(),v.end());
		ll L=1, R=1000000000000;
		ll ans=0;
		while(L<=R){
			ll mid=(L+R)/2;
			// mid가 가장 최소가 되도록
			bool flag=0;
			for(ll i=0;i<n;++i){
				if(v[i]<mid){
					flag=1;
					break;
				}
			}
			if(flag){
				R=mid-1;
				continue;
			}
			ll sum=0;
			for(ll i=0;i<n;++i){
				sum+=v[i]-mid;
			}
			if(sum>=s){
				ans=max(ans,mid);
				L=mid+1;
			}else{
				// s>=sum
				R=mid-1;
			}
		}
		cout<<ans;
	} 
	return 0;
}