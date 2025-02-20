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
		// n개의 정렬된 티는 n명이 테스터들에게 시험됨
		// 1~n, a[i]를 준비했음. j번째 테스터는 b[j] 마실 수 있음 한번에
		// i번쨰 테스터는 min(a[i],b[i])만큼을 먹음. a[i]는 감소함
		ll n;
		cin>>n;
		vector<ll> a(n,0), b(n,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}

		// psum[0]=b[0]
		// psum[1]=pum[0]+b[0]

		// sum[1]=b[0]
		// sum[2]=sum[1]+b[1]
		vector<ll> add_b(n+1,0), mul_b(n+1,0);
		vector<ll> psum(n,0);
		// a[i]+psum[i-1]
		for(ll i=0;i<n;++i){
			cin>>b[i];
			psum[i]=(i==0) ? b[0]: psum[i-1]+b[i];
		}
		// if(n==1){
		// 	cout<<min(a[0],b[0])<<"\n";
		// 	continue;
		// }
		for(ll i=0;i<n;++i){
			ll max_idx=-1;
			ll L=0, R=n-1;
			while(L<=R){
				ll mid=(L+R)/2;
				if(psum[mid]-psum[i]+b[i]<=a[i]){
					max_idx=max(max_idx,mid);
					L=mid+1;
				}else{
					R=mid-1;
				}
			}
			if(max_idx==-1){
				// max_idx=n-1;
				// psum
				add_b[i]+=a[i];
			}else{
				++mul_b[i];
				--mul_b[max_idx+1];
				add_b[max_idx+1]+=a[i]-(psum[max_idx]-psum[i]+b[i]);
			}
			
		}
		for(ll i=0;i<n;++i){
			// cout<<i<<" "<<mul_b[i]<<" "<<add_b[i]<<"\n";
			cout<<b[i]*mul_b[i]+add_b[i]<<" ";
			mul_b[i+1]+=mul_b[i];
		}cout<<"\n";
		
		

	} 	

	return 0;
}