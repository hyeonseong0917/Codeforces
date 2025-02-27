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
		ll min_num=2023101800;
		ll max_num=-2023101800;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			max_num=max(max_num,v[i]);
			min_num=min(min_num,v[i]);
		}
		if(min_num==max_num){
			cout<<n*(n-1)<<"\n";
			continue;
		}
		ll min_cnt=0, max_cnt=0;
		for(ll i=0;i<n;++i){
			if(v[i]==min_num){
				++min_cnt;
			}
			if(v[i]==max_num){
				++max_cnt;
			}
		}
		cout<<2*min_cnt*max_cnt<<"\n";

		
	} 
	return 0;
}