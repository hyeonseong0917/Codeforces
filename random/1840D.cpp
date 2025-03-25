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
		// 3명의 장인 존재
		// 손님 n명 존재. 각 손님은 패턴 a[i]를 가진 장난감 워함
		// 각 조각가는 x를 선택해 숙련도 쌓음
		// 서로 다른 패턴 선택 가능
		// 연습한 패턴 장난감은 즉시 제작 가능
		// 연습한 패턴과 다르다면 abs(x-y)만큼 걸림
		// 손님들이 최대한 적게 기다리도록 ㄴㄴ
		// 가장 길게 기다리는 사람의 시간이 최소가 되도록

		// 1 2 4 5 30 60

		// 1 4 4 14 19 37 59 73 98
		// 3 3 10 5 18 21 14 25
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		map<ll,ll> check;
		ll cnt=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			if(!check[v[i]]){
				++check[v[i]];
				++cnt;
			}
		}
		if(n<=3 || cnt<=3){
			cout<<0<<"\n";
			continue;
		}
		// n>4, 3개보다 다양한 수 존재함
		sort(v.begin(),v.end());
		// 가장 길게 기다리는 사람의 시간이 최소가 되도록
		ll L=1, R=1000000000;
		ll ans=R;
		while(L<=R){
			ll mid=(L+R)/2;
			ll fst_idx=0, sed_idx=n-1;
			for(ll i=0;i<n-1;++i){
				if(v[i+1]-v[0]<=mid*2){
					fst_idx=i+1;
				}else{
					break;
				}
			}
			for(ll i=n-1;i>=1;--i){
				if(v[n-1]-v[i-1]<=mid*2){
					sed_idx=i-1;
				}else{
					break;
				}
			}
			++fst_idx;
			--sed_idx;
			if(fst_idx>sed_idx || v[sed_idx]-v[fst_idx]<=mid*2){
				ans=min(ans,mid);
				R=mid-1;
			}else{
				L=mid+1;
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
}