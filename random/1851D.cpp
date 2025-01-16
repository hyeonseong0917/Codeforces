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
		for(ll i=1;i<n;++i){
			cin>>v[i];
		}
		if(n==2){
			if(v[1]==1 || v[1]==2 || v[1]==3){
				cout<<"YES"<<"\n";
			}else{
				cout<<"NO"<<"\n";
			}
			continue;
		}
		map<ll,ll> check;
		bool is_check=0;
		bool is_fail=0;
		ll cur_num=0;
		for(ll i=0;i<=n-2;++i){
			ll diff=v[i+1]-v[i];
			if(diff>n || check[diff]){
				// diff이 n보다 크거나 check라면
				// 생략된 수가 있었다는 것
				if(is_check){
					// 이미 여기 구간을 한 번 체크했음
					is_fail=1;
					break;
				}
				is_check=1;
				cur_num=diff;
			}else{
				++check[diff];
			}
		}
		if(is_fail){
			cout<<"NO"<<"\n";
		}else{
			if(!is_check){
				cout<<"YES"<<"\n";
				continue;
			}
			ll sum=0;
			for(ll i=1;i<=n;++i){
				if(!check[i]){
					sum+=i;
				}
			}
			if(sum==cur_num){
				cout<<"YES"<<"\n";
			}else{
				cout<<"NO"<<"\n";
			}
		}
	} 
	return 0;
}