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
		vector<ll> a(n,0);
		bool flag=1;
		for(ll i=0;i<n;++i){
			cin>>a[i];
			if(a[i]!=0){
				flag=0;
			}
		}
		if(flag){
			cout<<0<<"\n";
			continue;
		}
		sort(a.rbegin(),a.rend());
		ll psum=0;
		for(ll i=1;i<n;++i){
			psum+=a[i];
		}
		if(a[0]<=psum+1){
			cout<<1<<"\n";
		}else{
			cout<<a[0]-psum<<"\n";
		}

	} 
	return 0;
}