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
		if(n<=3){
			cout<<1<<"\n";
		}else{
			ll ans=1;
			while(n>3){
				ans*=2;
				n/=4;
			}
			cout<<ans<<"\n";
		}
	} 
	return 0;
}