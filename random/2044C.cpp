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
		ll m,a,b,c;
		cin>>m>>a>>b>>c;
		ll ans=min(m,a)+min(m,b);
		if(2*m>ans){
			ans+=min(c,2*m-ans);
		}
		cout<<ans<<"\n";

	} 
	return 0;
}