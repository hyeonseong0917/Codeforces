#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long
ll mod=998244353;
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> b(n-1,0), a(n,0);
		for(ll i=0;i<n-1;++i){
			cin>>b[i];
		}
		a[0]=b[0];
		for(ll i=1;i<n-1;++i){
			if(a[i-1]>=b[i]){
				a[i]=b[i];
				a[i+1]=0;
			}else{
				a[i+1]=b[i];
			}
		}
		for(ll i=0;i<n;++i){
			cout<<a[i]<<" ";
		}cout<<"\n";
	} 
	return 0;
}