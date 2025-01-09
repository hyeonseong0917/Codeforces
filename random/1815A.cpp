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
	ll t=1;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		if(n==2){
			if(v[0]>v[1]){
				cout<<"NO"<<"\n";
			}else{
				cout<<"YES"<<"\n";
			}
			continue;
		}
		if(n%2==1){
			cout<<"YES"<<"\n";
			continue;
		}
		vector<ll> diff(n-1,0);
		for(ll i=0;i<n-1;++i){
			diff[i]=v[i+1]-v[i];
		}
		ll sum=0;
		for(ll i=1;i<n-1;++i){
			if(i%2==0){
				sum+=diff[i];
			}
		}
		if(sum<0){
			cout<<"NO"<<"\n";
		}else{
			cout<<"YES"<<"\n";
		}
	}
	return 0;
}