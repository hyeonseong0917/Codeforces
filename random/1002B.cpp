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
		vector<ll> a(n,0), b(n,0);
		map<ll,ll> ac, bc;
		ll a_cnt=0, b_cnt=0;
		for(ll i=0;i<n;++i){
			cin>>a[i];
			if(!ac[a[i]]){
				++ac[a[i]];
				++a_cnt;
			}
		}
		for(ll i=0;i<n;++i){
			cin>>b[i];
			if(!bc[b[i]]){
				++bc[b[i]];
				++b_cnt;
			}
		}
		if(a_cnt*b_cnt>=3){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}

	} 
	return 0;
}