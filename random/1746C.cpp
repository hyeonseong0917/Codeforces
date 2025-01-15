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
		vector<ll> v(n+1,0);
		vector<ll> pos(n+1,0);
		for(ll i=1;i<=n;++i){
			cin>>v[i];
			pos[v[i]]=i;
		}
		for(ll i=1;i<=n;++i){
			if(pos[i]==n){
				cout<<1<<" ";
			}else{
				cout<<pos[i]+1<<" ";
			}
		}
		cout<<"\n";

	} 
	return 0;
}