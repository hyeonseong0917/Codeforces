#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll sum=0;
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> psum(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		psum[0]=v[0];
		for(ll i=1;i<n;++i){
			psum[i]=psum[i-1]+v[i];
		}
		ll cnt=0;
		bool is_good=0;
		if(v[0]==0){
			is_good=1;
			++cnt;
		}
		ll max_num=v[0];
		for(ll i=1;i<n;++i){
			if(is_good){
				if(v[i]==0){
					++cnt;
				}else{
					if(v[i]==psum[i-1]){
						++cnt;
					}else{
						is_good=0;
					}
				}
			}else{
				if(v[i]==psum[i-1]){
					is_good=1;
					++cnt;
				}else{
					if(psum[i]-max_num==max_num){
						++cnt;
						is_good=1;
					}
				}
			}
			max_num=max(max_num,v[i]);
		}
		cout<<cnt<<"\n";
	}
	
	return 0;
}