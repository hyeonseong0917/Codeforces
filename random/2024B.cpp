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
		// 1314
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		// 현재 인덱스 i에서 n개의 버튼 누르면 
		// (n-i)점 획득 가능함
		// 현재 인덱스 i에서 v[i]번 누르기 가능함
		sort(v.begin(),v.end());
		ll cnt=0; // 누른 횟수
		ll sum=0; // 현재 가지고 있는 캔의 개수
		ll w=0; // 지금까지 누적된 가중치

		// 3 4
		// 1 2 3
		// 0 2 3 cnt=1, sum=1
		// 0 0 3 cnt=3, sum=5

		// 0 1 2 3 4 5 6 7
		// 0 0 0 4 4 5 6 7
		
		// 0 1 2 3 4
		// 0 0 0 4 9
		// 10
		for(ll i=0;i<n;++i){
			// cout<<i<<" "<<cnt<<" "<<sum<<"\n";
			v[i]-=w;
			if(v[i]<=0) continue;
			if(sum+v[i]*(n-i)>=k){
				// 0 0 0 5 5 6 9 10 24 24
				for(ll j=i+1;j<n;++j){
					v[j]-=w;
				}
				ll L=0, R=v[i];
				ll c=0;
				while(L<=R){
					ll mid=(L+R)/2;
					if(sum+mid*(n-i)>=k){
						R=mid-1;
					}else{
						c=max(mid,c);
						L=mid+1;
					}
				}
				sum+=c*(n-i);
				ll d=k-sum;
				sum+=i;
				sum+=d;
				break;
			}else{
				sum+=v[i]*(n-i);
				// cnt+=v[i]*n;
				w+=v[i];
				v[i]=0;
			}
		}
		cout<<sum<<"\n";

	} 	

	return 0;
}