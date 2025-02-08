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
	// 1053
	while(t--){
		ll n;
		cin>>n;
		vector<ll> a(n,0), b(n,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		for(ll i=0;i<n;++i){
			cin>>b[i];
		}
		ll L,R;
		for(ll i=0;i<n;++i){
			if(a[i]!=b[i]){
				L=i;
				break;
			}
		}
		for(ll i=n-1;i>=0;--i){
			if(a[i]!=b[i]){
				R=i;
				break;
			}
		}
		ll min_num=2023101800;
		ll max_num=-2023101800;
		for(ll i=L;i<=R;++i){
			min_num=min(min_num,a[i]);
			max_num=max(max_num,a[i]);
		}
		while(1){
			bool flag=0;
			// L-1 넣을 수 있는지?
			if(L-1>=0){
				if(a[L-1]<=min_num){
					min_num=a[L-1];
					--L;
					flag=1;
				}
			}
			// R+1
			if(R+1<=n-1){
				if(a[R+1]>=max_num){
					max_num=a[R+1];
					++R;
					flag=1;
				}
			}
			if(!flag) break;
		}
		cout<<L+1<<" "<<R+1<<"\n";
	} 	

	return 0;
}