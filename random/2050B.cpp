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
		}else{
			ll q=sum/n;
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
			if(fst_sum%fst_cnt==0 && sed_sum%sed_cnt==0){
				if(fst_sum/fst_cnt==q && sed_sum/sed_cnt==q){
					cout<<"YES"<<"\n";
				}else{
					cout<<"NO"<<"\n";
				}
			}else{
				cout<<"NO"<<"\n";
			}
		}
		
	} 
	return 0;
}