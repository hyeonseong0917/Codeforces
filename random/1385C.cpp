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
	int t=0;
	cin>>t;
	while(t--){
		// n개의 정수로 이루어진 배열 a
		// 가장 최소의 prefix길이를 구하고 싶음
		// a로부터 지워야 하는, good array로 만들기 위해
		// 길이 m의 수열 b는 good이라고 불린다 만약
		// 비내림차순 수열 c를 얻을 수 있으면
		// 해당 operation을 m번 반복해서
		// b의 처음이나 마지막 원소 골라서 b에서 제거하고
		// c의 끝에 추가함
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		if(n==1){
			cout<<0<<"\n";
			continue;
		}
		// 최대의 suffix 길이를 구하다
		ll L=1, R=n;
		ll ans=0;
		while(L<=R){
			ll mid=(L+R)/2;
			ll l=n-mid;
			ll r=n-1;
			ll cur_num=-1;
			bool flag=0;
			while(l<=r){
				if(v[l]<=v[r]){
					if(cur_num>v[l]){
						flag=1;
						break;
					}
					cur_num=v[l];
					++l;
				}else{
					if(cur_num>v[r]){
						flag=1;
						break;
					}
					cur_num=v[r];
					--r;
				}
			}
			if(flag){
				R=mid-1;
			}else{
				ans=max(ans,mid);
				L=mid+1;
			}
		}
		cout<<n-ans<<"\n";

	} 
	return 0;
}