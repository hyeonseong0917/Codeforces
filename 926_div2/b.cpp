#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		ll ans;
		if(k<=(2*n-2)*2){
			ans=(k+1)/2;
		}else{
			ans=2*n-2+(k-(2*n-2)*2);
		}
		cout<<ans<<"\n";
	}	
	return 0;
}