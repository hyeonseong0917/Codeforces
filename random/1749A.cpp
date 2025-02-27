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
		ll n,m;
		cin>>n>>m;
		// n*n의 체스보드
		for(ll i=0;i<m;++i){
			ll x,y;
			cin>>x>>y;
			
		}
		if(m==1){
			if(n==1){
				cout<<"NO"<<"\n";
			}else{
				cout<<"YES"<<"\n";
			}
			continue;
		}
		if(m<n){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
	} 
	return 0;
}