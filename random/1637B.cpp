#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
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
	cin>>t;
	while(t--){
		// b1,b2..bk
		// [l1:r1], [l2:r2]...[lc:rc]
		// r[i-1]+1=l[i]
		// cost=c+mex(b[l[i]],b[l[i]+1]...b[r[i]])
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		// 각 subsegment에 대해 구간의 개수+ 각 구간의 MEX
		// 길이, 0이 있는 구간이라면 +1
		// 2 0 5 1
		// 2,0,5,1=>5
		// 2,0,5=>4
		// 0,5,1=>4
		// 2,0=>3
		// 0,5=>3
		// 5,1=>2
		// 5
		ll ans=0;
		for(ll i=1;i<=n;++i){
			// i는 길이
			for(ll j=0;j+i<=n;++j){
				// j는 시작점
				// [j:j+i-1]에 0있는지?
				ll c=0;
				for(ll k=j;k<j+i;++k){
					if(v[k]==0){
						++c;
					}
				}
				ans+=i+c;
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
}