#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n,x;
		cin>>n>>x;
		ll sum=0;
		ll max_num=0;
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			sum+=a;
			max_num=max(max_num,a);
		}
		cout<<max(max_num,(sum+x-1)/x)<<"\n";
	}
	return 0;
}