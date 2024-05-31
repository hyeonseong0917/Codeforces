#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> a(n,0), b(n+1,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		for(ll i=0;i<n+1;++i){
			cin>>b[i];
		}
		bool flag=0;
		ll cnt=0;
		ll min_diff=12222232421;
		for(ll i=0;i<n;++i){
			if((a[i]<=b[n] && b[n]<=b[i]) || (b[i]<=b[n] && b[n]<=a[i])){
				flag=1;
			}
			cnt+=abs(a[i]-b[i]);
			min_diff=min(min_diff,min(abs(a[i]-b[n]),abs(b[i]-b[n])));
		}
		if(flag){
			++cnt;
		}else{
			cnt+=min_diff+1;
		}
		cout<<cnt<<"\n";
	}
	return 0;
}