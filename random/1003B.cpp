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
		string s;
		cin>>s;
		ll n=s.size();
		bool flag=0;
		ll ans=-1;
		for(ll i=0;i<n-1;++i){
			if(s[i]==s[i+1]){
				ans=i;
				break;
			}
		}
		if(ans==-1){
			cout<<n<<"\n";
		}else{
			cout<<1<<"\n";
		}

	} 	

	return 0;
}