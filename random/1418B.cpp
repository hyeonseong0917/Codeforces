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
		vector<ll> a(n,0),b(n,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		vector<ll> c;
		for(ll i=0;i<n;++i){
			cin>>b[i];
			if(!b[i]){
				c.push_back(a[i]);
			}
		}
		sort(c.rbegin(),c.rend());
		ll idx=0;
		for(ll i=0;i<n;++i){
			if(b[i]){
				cout<<a[i]<<" ";
			}else{
				cout<<c[idx++]<<" ";
			}
		}
		cout<<"\n";
		
	} 

	return 0;
}