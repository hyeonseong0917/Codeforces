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
	ll t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		if(n%2==0){
			cout<<-1<<"\n";
		}else{
			ll m=n/2;
			vector<ll> ans;
			map<ll,ll> check;
			ll tmp=n;
			while(m--){
				ans.push_back(n);
				++check[n];
				--n;
			}

			for(ll i=1;i<=tmp;++i){
				if(!check[i]){
					ans.push_back(i);
				}
			}
			for(ll i=0;i<tmp;++i){
				cout<<ans[i]<<" ";
			}cout<<"\n";
		}
	}
	return 0;
}