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
		if(n==1){
			if(v[0]%2==0){
				cout<<0<<"\n";
			}else{
				cout<<-1<<"\n";
			}
			continue;
		}
		// v[i]*i가 한 operation
		// 최소의 operation 횟수로 2^n의 배수가 되도록?

		// 2^x값이 큰 것부터 곱하는게 유리
		// n=3
		// 1 2 3 => 2가 1개
		// 10 6 11 => 2가 2개
		// (1) 2가 몇 개 부족한지??
		// (2) n보다 작거나 같은 최대의 2^x를 구한다
		// (3) [2^x, k*2^(x-1),p*2^(x-2)...]를 구한다
		ll sum=0;
		for(ll i=0;i<n;++i){
			ll cur_num=v[i];
			while(cur_num%2==0 && cur_num!=1){
				++sum;
				cur_num/=2;
			}
		}
		if(sum>=n){
			cout<<0<<"\n";
			continue;
		}
		ll x=0;
		while(1){
			if((ll)pow(2,x+1)<=n){
				++x;
			}else{
				break;
			}
		}
		ll ans=0;
		for(ll i=x;i>=1;--i){
			// 1~n까지 2의 i제곱의 배수가 몇 개 있는지??
			// 3*pow(2,i), 5*(pow(2,i))
			ll cur_num=(ll)pow(2,i);
			ll k=1;
			while(sum<n){
				if(k*cur_num<=n){
					sum+=i;
					k+=2;
					++ans;
				}else{
					break;
				}
			}
			if(sum>=n){
				break;
			}
			
		}
		if(sum>=n){
			cout<<ans<<"\n";
		}else{
			cout<<-1<<"\n";
		}
	} 
	return 0;
}