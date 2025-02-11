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
		if(n==1){
			cout<<0<<"\n";
			continue;
		}
		string ans="1";
		for(ll i=0;i<n-1;++i){
			ans+='0';
		}
		cout<<ans<<"\n";
	} 	

	return 0;
}