#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
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
		ll n;
		cin>>n;
		ll sum=0;
		for(ll i=0;i<n;++i){
			ll a=0;
			cin>>a;
			sum+=a;
		}
		ll cur_num=sqrt(sum);
		if(cur_num*cur_num==sum){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
	}	
	return 0;
}