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
		ll n,k;
		cin>>n>>k;
		vector<ll> v(k,0);
		for(ll i=0;i<k;++i){
			cin>>v[i];
		}
		if(n==1 || k==1){
			cout<<"YES"<<"\n";
			continue;
		}
		ll last_num=-2023101800;
		bool flag=0;
		for(ll i=k-1;i>=1;--i){
			ll cur_num=v[i]-v[i-1];
			if(last_num<cur_num && last_num!=-2023101800){
				flag=1;
				break;
			}
			last_num=cur_num;
		}
		if(last_num*(n-k+1)<v[0] || flag){
			cout<<"NO"<<"\n";
		}else{
			// last_num*(n-k+1)>=v[0]
			cout<<"YES"<<"\n";
		}
	} 
	return 0;
}