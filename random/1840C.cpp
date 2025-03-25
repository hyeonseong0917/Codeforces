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
		// n일 동안 휴가를 보내다
		// 연속된 날들을 할당. 최소 k일 동안
		// i번째 날의 온도는 a[i]
		// q도 위로 오르지 않았을 때만 여행 가능
		ll n,k,q;
		cin>>n>>k>>q;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		// 6 1 3
		// 0 1  2 3  4  5
		// 0 3 -2 5 -4 -4

		// [0:2], [4:5]
		
		// 5+3+1

		// 최소 k일 이상
		// [0:2]
		// 3+2+1
		// [3,2]
		ll cnt=0;
		vector<ll> tmp;
		for(ll i=0;i<n;++i){
			if(v[i]>q){
				if(cnt!=0){
					tmp.push_back(cnt);
					cnt=0;
				}
			}else{
				++cnt;
			}
		}
		if(cnt!=0){
			tmp.push_back(cnt);
		}
		// [3,2]
		ll ans=0;
		for(ll i=0;i<tmp.size();++i){
			if(tmp[i]<k) continue;
			// tmp[i]>=k
			// [1~tmp[i]-k+1]
			ll c=tmp[i]-k+1;
			ans+=((c+1)*c)/2;
		}
		cout<<ans<<"\n";

	} 
	return 0;
}