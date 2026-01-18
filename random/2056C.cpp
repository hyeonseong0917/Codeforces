#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long
#define pb push_back

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
		if(n%2==0){
			v[0]=1;
			v[n-1]=1;
			v[n/2]=1;
			ll cnt=2;
			for(ll i=0;i<n;++i){
				if(!v[i]){
					v[i]=cnt++;
				}
			}
		}else{
			for(ll i=0;i<=n/2;++i){
				v[i]=i+1;
			}
			ll cnt=1;
			for(ll i=n/2+1;i<n;++i){
				v[i]=cnt++;
			}
		}
		for(ll i=0;i<n;++i){
			cout<<v[i]<<" ";
		}cout<<"\n";
	}
	return 0;
}