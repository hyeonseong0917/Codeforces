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
		ll n;
		cin>>n;
		vector<ll> a(n,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		
		if(n==1){
			cout<<"YES"<<"\n";
			continue;
		}
		for(ll i=n-2;i>=0;i-=2){
			if(a[i]>a[i+1]){
				ll tmp=a[i];
				a[i]=a[i+1];
				a[i+1]=tmp;
			}
		}
		bool flag=0;
		for(ll i=0;i<n-1;++i){
			if(a[i]>a[i+1]){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<"NO"<<"\n";
		}else{
			cout<<"YES"<<"\n";
		}
	} 
	return 0;
}
