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
		string a,b;
		cin>>a;
		cin>>b;
		queue<ll> zero_idx[2];
		queue<ll> one_idx[2];
		for(ll i=0;i<n;++i){
			if(a[i]=='0'){
				zero_idx[i%2].push(i);
			}else{
				one_idx[i%2].push(i);
			}
		}
		bool flag=0;
		ll ans=0;
		for(ll i=0;i<n && !flag;++i){
			if(a[i]!=b[i]){
				if(a[i]=='0'){
					while(!one_idx[i%2].empty()){
						ll cur_idx=one_idx[i%2].front();
						if(cur_idx<i){
							one_idx[i%2].pop();
						}else{
							break;
						}
					}
					if(one_idx[i%2].empty()){
						flag=1;
					}else{
						ans+=(one_idx[i%2].front()-i)/2;
						a[one_idx[i%2].front()]='0';
						one_idx[i%2].pop();
					}
				}else{
					while(!zero_idx[i%2].empty()){
						ll cur_idx=zero_idx[i%2].front();
						if(cur_idx<i){
							zero_idx[i%2].pop();
						}else{
							break;
						}
					}
					if(zero_idx[i%2].empty()){
						flag=1;
					}else{
						ans+=(zero_idx[i%2].front()-i)/2;
						a[zero_idx[i%2].front()]='1';
						zero_idx[i%2].pop();
					}
				}
			}
		}
		if(!flag){
			cout<<ans<<"\n";
		}else{
			cout<<-1<<"\n";
		}
	} 	

	return 0;
}