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
		vector<ll> c(n,0);
		bool is_all_minus=1;
		ll max_num=-2023101800;
		for(ll i=0;i<n;++i){
			cin>>c[i];
			if(c[i]>=0){
				is_all_minus=0;
			}
			max_num=max(max_num,c[i]);
		}
		if(is_all_minus){
			cout<<max_num<<"\n";
		}else{
			ll even_sum=0, odd_sum=0;
			for(ll i=0;i<n;++i){
				if(i%2==0){
					even_sum+=max(c[i],(ll)0);
				}else{
					odd_sum+=max(c[i],(ll)0);
				}
			}
			cout<<max(even_sum,odd_sum)<<"\n";
		}
	} 
	return 0;
}