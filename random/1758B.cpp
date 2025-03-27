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
		vector<ll> v(n,0);
		bool flag=0;
		ll zero_cnt=0;
		vector<ll> tmp;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			if(!v[i]){
				flag=1;
				++zero_cnt;
			}else{
				tmp.push_back(v[i]);
			}
		}
		// 0 1 0
		// 0 1 0 2 0 3 0
		// 
		if(zero_cnt<=n-zero_cnt+1){
			cout<<0<<"\n";
		}else{
			if(tmp.empty()){
				cout<<1<<"\n";
			}else{
				sort(tmp.rbegin(),tmp.rend());
				if(tmp[0]==1){
					cout<<2<<"\n";
				}else{
					cout<<1<<"\n";
				}
			}
		}

	} 
	return 0;
}