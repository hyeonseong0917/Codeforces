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
		vector<ll> check(n+1,0);
		vector<ll> v;
		vector<ll> p;
		for(ll i=0;i<n;++i){
			cin>>a[i];
			if(a[i]>n){
				p.push_back(a[i]);
				continue;
			}
			// a[i]<=n
			if(!check[a[i]]){
				++check[a[i]];
			}else{
				p.push_back(a[i]);
			}
		}
		for(ll i=1;i<=n;++i){
			if(!check[i]){
				v.push_back(i);
			}
		}
		sort(p.begin(),p.end());
		ll vs=v.size();
		ll ps=p.size();
		// cout<<vs<<" "<<ps<<"\n";
		bool flag=0;
		for(ll i=0;i<ps;++i){
			if(p[i]<v[i]*2+1){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<-1<<"\n";
		}else{
			cout<<ps<<"\n";
		}
	} 
	return 0;
}