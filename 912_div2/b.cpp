#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll N;
		cin>>N;
		vector<ll> v;
		for(ll i=0;i<N;++i){
			ll a=0;
			cin>>a;
			v.push_back(a);
		}
		ll psum[100000+1];
		psum[N-1]=v[N-1];
		for(int i=N-2;i>=0;--i){
			psum[i]=psum[i+1]+v[i];
		}
		ll sum=psum[0];
		// cout<<sum<<"\n";
		for(int i=1;i<N;++i){
			if(psum[i]>0){
				sum+=psum[i];
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}