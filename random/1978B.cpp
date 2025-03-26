#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n,a,b;
		cin>>n>>a>>b;
		ll fst_num=n*a;
		ll k=min(n,b);
		ll sed_num=(n-k)*a+(b*(b+1)-(b-k)*(b-k+1))/2;
		// 4 4 5
		// k=4
		cout<<max(fst_num,sed_num)<<"\n";
	} 
	return 0;
}