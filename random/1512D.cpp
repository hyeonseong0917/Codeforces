#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n+2,0);
		for(ll i=0;i<n+2;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		vector<ll> psum(n+2,0);
		psum[0]=v[0];
		for(ll i=1;i<n+2;++i){
			psum[i]=psum[i-1]+v[i];
		}
		// 2 2 3 7 12
		bool flag=0;
		ll x=-1;
		ll idx=-1;
		for(ll i=0;i<n+1;++i){
			// i번째가 x임
			// cout<<psum[n-2]<<" "<<v[i]<<" "<<v[n-1]<<"\n";
			if(psum[n]-v[i]==v[n+1]){
				flag=1;
				x=i;
				idx=n+1;
				// cout<<idx<<endl;
			}
		}
		if(psum[n-1]==v[n]){
			flag=1;
			x=n;
			idx=n+1;
		}
		if(!flag){
			cout<<-1<<"\n";
		}else{
			for(ll i=0;i<n+2;++i){
				if(i==x || i==idx) continue;
				cout<<v[i]<<" ";
			}cout<<"\n";
		}
	} 

	return 0;
}