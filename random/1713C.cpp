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
		if(n==1){
			cout<<0<<"\n";
			continue;
		}
		vector<ll> v(n,-1);
		map<ll,ll> check;
		ll cur_double_num=n-1;
		ll idx=n-1;
		while(idx>=0 && cur_double_num>=0){
			ll sqrt_cur_num=sqrt(cur_double_num);
			if(sqrt_cur_num*sqrt_cur_num!=cur_double_num){
				cur_double_num=(sqrt_cur_num+1)*(sqrt_cur_num+1);
			}
			if(cur_double_num-idx>idx){
				cur_double_num=(sqrt_cur_num-1)*(sqrt_cur_num-1);
				continue;
			}
			for(ll i=idx;i>=cur_double_num-idx;--i){
				v[i]=cur_double_num-i;
				++check[v[i]];
			}
			idx=cur_double_num-idx-1;
		}
		bool flag=0;
		for(ll i=0;i<n;++i){
			if(v[i]==-1 || check[v[i]]>=2){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<-1<<"\n";
			continue;
		}
		for(ll i=0;i<n;++i){
			cout<<v[i]<<" ";
		}cout<<"\n";
	} 
	return 0;
}