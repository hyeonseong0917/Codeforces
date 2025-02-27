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
		bool is_zero=0;
		ll minus_num=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			if(v[i]==0){
				is_zero=1;
			}
			if(v[i]<0){
				++minus_num;
			}
		}
		ll sum=0;
		if(is_zero){
			for(ll i=0;i<n;++i){
				sum+=abs(v[i]);
			}
			cout<<sum<<"\n";
			continue;
		}
		if(minus_num%2==0){
			for(ll i=0;i<n;++i){
				sum+=abs(v[i]);
			}
		}else{
			for(ll i=0;i<n;++i){
				sum+=abs(v[i]);
			}
			ll min_num=2023101800;
			for(ll i=0;i<n;++i){
				min_num=min(min_num,abs(v[i]));
			}
			sum-=min_num*2;
		}
		cout<<sum<<"\n";
		// 0 1 5 -5 5 1 0
		// 0 있다면 무조건 다 양수로 가능
		// -1 1 2 3 4 -1 0
	} 
	return 0;
}