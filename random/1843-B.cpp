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
		// operation을 원하는 만큼 할 수 있음
		// l<=r 을 골라서 모든 원소에 -1을 곱한다
		// 가능한 한 최대의 합과 최소의 operation

		// -1 7 -4 -2 5 -8
		// -구간의 개수
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		ll sum=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			sum+=(v[i]<0)?v[i]*-1:v[i];
		}
		ll cnt=0;
		bool flag=0;
		for(ll i=0;i<n;++i){
			if(v[i]>0 && flag){
				++cnt;
				flag=0;
			}else{
				if(v[i]<0){
					flag=1;
				}
			}
		}
		if(flag){
			++cnt;
		}
		cout<<sum<<" "<<cnt<<"\n";
	} 
	return 0;
}