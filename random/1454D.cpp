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
		ll n;
		cin>>n;
		bool is_prime=1;
		ll max_num=0;
		ll max_cnt=0;
		for(ll i=2;i<=sqrt(n);++i){
			if(n%i==0){
				is_prime=0;
				ll cur_cnt=0;
				ll tmp=n;
				while(tmp%i==0){
					tmp/=i;
					++cur_cnt;
				}
				if(cur_cnt>max_cnt){
					max_cnt=cur_cnt;
					max_num=i;
				}
			}
		}
		if(is_prime){
			cout<<1<<"\n";
			cout<<n<<"\n";
		}else{
			ll last_num=1;
			for(ll i=0;i<max_cnt;++i){
				last_num*=max_num;
			}
			last_num=n/last_num;
			last_num*=max_num;
			cout<<max_cnt<<"\n";
			for(ll i=0;i<max_cnt-1;++i){
				cout<<max_num<<" ";
			}cout<<last_num<<"\n";
		}
	} 	

	return 0;
}