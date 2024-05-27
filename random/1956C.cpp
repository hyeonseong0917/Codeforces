#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
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
		if(n==1){
			cout<<1<<" "<<1<<"\n";
			cout<<1<<" "<<1<<" "<<1<<"\n";
			continue;
		}
		ll sum=0;
		ll mul=1;
		// 1 2*3 3*5
		for(ll i=1;i<=n;++i){
			sum+=(i*mul);
			mul+=2;
		}
		cout<<sum<<" "<<n*2<<"\n";
		ll cnt=0;
		for(ll i=n;i>=1;--i){
			cout<<1<<" "<<i<<" ";	
			for(ll j=1;j<=n;++j){
				cout<<j;
				if(j!=n){
					cout<<" ";
				}
			}
			cout<<"\n";
			cout<<2<<" "<<i<<" ";	
			for(ll j=1;j<=n;++j){
				cout<<j;
				if(j!=n){
					cout<<" ";
				}
			}
			cout<<"\n";
		}
	}
	return 0;
}