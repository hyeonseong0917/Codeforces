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
		ll sum=0;
		ll ans=0;
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			sum+=a;
			ll k=sqrt(sum);
			// cout<<k<<endl;
			if(k*k==sum){
				if(k%2==1){
					++ans;
				}
				
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
}