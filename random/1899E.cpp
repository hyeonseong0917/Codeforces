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
		ll n,m;
		cin>>n;
		vector<ll> a(n,0), b(n,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		map<ll,ll> need;
		for(ll i=0;i<n;++i){
			cin>>b[i];
			++need[b[i]];
		}
		cin>>m;
		vector<ll> d(m,0);
		map<ll,ll> store;
		bool flag=0;
		for(ll i=0;i<m;++i){
			cin>>d[i];
			++store[d[i]];
		}
		if(!need[d[m-1]]){
			flag=1;
		}
		
		for(ll i=0;i<n;++i){
			if(a[i]!=b[i]){
				if(store[b[i]]){
					--store[b[i]];
				}else{
					flag=1;
					break;
				}
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