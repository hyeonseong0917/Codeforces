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
		if(n<=2){
			if(n==1){
				cout<<"YES"<<"\n";
			}else{
				if(v[0]==v[1]){
					if(v[0]==0){
						cout<<"NO"<<"\n";
					}else{
						cout<<"YES"<<"\n";
					}
					// cout<<"NO"<<"\n";
				}else{
					cout<<"YES"<<"\n";
				}
			}
			continue;
		}
		ll L=0, R=n-1;
		ll cur_num=0;
		bool flag=0;
		if(n%2==1){
			while(L<=R){
				if(L==R){
					if(v[L]<cur_num){
						flag=1;
					}
					break;
				}
				if(v[L]>=cur_num && v[R]>=cur_num){
					++cur_num;
					++L;
					--R;
				}else{
					flag=1;
					break;
				}
			}
		}else{
			while(L<=R){
				if(L+1==R){
					// cur_num과 cur_num+1
					if(v[L]>=cur_num && v[R]>=cur_num+1){
						break;
					}
					if(v[L]>=cur_num+1 && v[R]>=cur_num){
						break;
					}
					flag=1;
					break;
				}
				if(v[L]>=cur_num && v[R]>=cur_num){
					++cur_num;
					++L;
					--R;
				}else{
					flag=1;
					break;
				}
			}
		}
		if(flag){
			cout<<"NO"<<"\n";
		}else{
			cout<<"YES"<<"\n";
		}
	} 


	return 0;
}