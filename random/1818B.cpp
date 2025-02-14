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
		if(n%2==1){
			if(n==1){
				cout<<1<<"\n";
			}else{
				cout<<-1<<"\n";
			}
		}else{
			vector<ll> v(n,0);
			ll idx=0;
			while(idx<n-1){
				v[idx]=idx+2;
				v[idx+1]=idx+1;
				idx+=2;
			}
			for(ll i=0;i<n;++i){
				cout<<v[i]<<" ";
			}cout<<"\n";
		}
	} 	

	return 0;
}