#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
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
		ll sum=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			sum+=v[i];
		}
		if(sum%n!=0){
			cout<<"NO"<<"\n";
			continue;
		}
		ll Q=sum/n;

		// 인덱스 1에서 n-2까지 인덱스 하나 선택
		// a[i-1]을 1 감소, a[i+1]을 1 증가
		// a[i-1]을 1 증가, a[i+1]을 1 감소
		// 중 택1
		// 모든 원소를 같게 만들 수 있는지??
		// 홀수 인덱스끼리만 값 주고받기 가능, 짝수 인덱스끼리만 값
		ll fst_sum=0;
		ll fst_cnt=0;
		ll sed_sum=0;
		ll sed_cnt=0;
		for(ll i=0;i<n;++i){
			if(i%2==0){
				fst_sum+=v[i];
				++fst_cnt;
			}else{
				sed_sum+=v[i];
				++sed_cnt;
			}
		}
		if(fst_sum==fst_cnt*Q && sed_sum==sed_cnt*Q){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
		
	} 
	return 0;
}