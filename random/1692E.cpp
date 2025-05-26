#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		// 하나의 operation에서 첫 번째 원소나 마지막 원소 제거 가능
		// 최소의 operation 수행해서 sum이 s가 되도록 할 수 있는지?
		ll n,s;
		cin>>n>>s;
		vector<ll> v(n,0);
		ll sum=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			sum+=v[i];
		}
		if(sum<s){
			cout<<-1<<"\n";
		}else{
			// sum>=s
			ll diff=sum-s;
			// 최소한움직임으로 diff개의 1을 지워야 한다.
		}

	} 
	return 0;
}