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
		ll n,m,r,c;
		cin>>n>>m>>r>>c;
		ll ans=m-c;
		ans+=(n-r)*m+(n-r)*(m-1);
		cout<<ans<<"\n";

	} 
	return 0;
}