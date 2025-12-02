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
		string ans="L";
		// 큰거->작은거->큰거->작은거
		ll cur_num=v[0];
		bool flag=0;
		ll L=1, R=n-1;
		while(L<=R){
			if(L==R){
				ans+='L';
				break;
			}
			if(!flag){
				// cur_num보다 큰거가 와야함
				// 1. 둘 다 cur_num보다 크다면?
				if(v[L]>cur_num && cur_num<v[R]){
					// L과 R중 더 큰게 와야함
					if(v[L]>v[R]){
						ans+='L';
						cur_num=v[L];
						++L;
					}else{
						ans+='R';
						cur_num=v[R];
						--R;
					}
					flag=1;
				}else if(v[L]<cur_num && v[R]<cur_num){
					// 2. 둘 다 cur_num보다 작다면?
					flag=1;
				}else{
					if(v[L]>cur_num){
						ans+='L';
						cur_num=v[L];
						++L;
					}else{
						ans+='R';
						cur_num=v[R];
						--R;
					}
					flag=1;
				}
			}else{
				// cur_num보다 작은게 와야함
				// 1. 둘 다 cur_num보다 크다면?
				if(v[L]>cur_num && cur_num<v[R]){
					flag=0;
				}else if(v[L]<cur_num && v[R]<cur_num){
					// 2. 둘 다 cur_num보다 작다면?
					// L과 R중 더 작은게 와야함
					if(v[L]<v[R]){
						ans+='L';
						cur_num=v[L];
						++L;
					}else{
						ans+='R';
						cur_num=v[R];
						--R;
					}
					flag=0;
				}else{
					if(v[L]<cur_num){
						ans+='L';
						cur_num=v[L];
						++L;
					}else{
						ans+='R';
						cur_num=v[R];
						--R;
					}
					flag=0;
				}
			}
		}
		cout<<ans<<"\n";
	} 

	return 0;
}