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
		ll n,m,k;
		cin>>n>>m>>k;
		vector<ll> v(n,0),sv(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
			sv[i]=v[i];
		}
		sort(sv.begin(),sv.end());
		map<ll,ll> buy;
		for(ll i=0;i<n;++i){
			if(m>=k){
				buy[sv[i]]+=k;
				break;
			}else{
				buy[sv[i]]+=m;
				k-=m;
			}
		}
		ll prem=0;
		ll sum=0;
		for(ll i=0;i<n;++i){
			if(buy[v[i]]){
				ll cur_buy=min(buy[v[i]],m);
				sum+=(v[i]+prem)*cur_buy;
				buy[v[i]]-=cur_buy;
				prem+=cur_buy;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}