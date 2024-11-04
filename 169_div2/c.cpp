#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o;
	cin>>o;
	while(o--){
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		for(ll i=n-2;i>=0;i-=2){
			if(v[i]+k>=v[i+1]){
				ll diff=v[i+1]-v[i];
				v[i]=v[i+1];
				k-=diff;
			}else{
				v[i]+=k;
				break;
			}
		}
		ll A=0, B=0;
		ll cnt=0;
		for(ll i=n-1;i>=0;--i){
			if(cnt%2==0){
				A+=v[i];
			}else{
				B+=v[i];
			}
			++cnt;
		}
		cout<<A-B<<"\n";
	}
	return 0;
}