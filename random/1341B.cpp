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
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0),p(n,0),psum(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		for(ll i=1;i<n-1;++i){
			if(v[i]>v[i-1] && v[i]>v[i+1]){
				p[i]=1;
			}
		}
		for(ll i=1;i<n;++i){
			psum[i]=psum[i-1]+p[i];
			// cout<<i<<" "<<psum[i]<<"\n";
		}
		ll L=0;
		ll max_num=psum[L+k-2]-psum[L+1]+p[1];
		// cout<<max_num<<"\n";
		for(ll i=1;i+k-1<n;++i){
			if(max_num<psum[i+k-2]-psum[i+1]+p[i+1]){
				// cout<<"he";
				L=i;
				max_num=psum[i+k-2]-psum[i+1]+p[i+1];
			}
		}
		++L;
		++max_num;
		cout<<max_num<<" "<<L<<"\n";
	} 	

	return 0;
}