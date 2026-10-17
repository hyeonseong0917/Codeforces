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
		ll n,m;
		cin>>n>>m;
		vector<ll> a(n,0);
		vector<ll> b(m,0);
		vector<ll> psum(n,0);
		for(int i=0;i<n;++i){
			cin>>a[i];
			psum[i]=(i==0)?a[i]:psum[i-1]+a[i];
		}
		for(int i=0;i<m;++i){
			cin>>b[i];
			--b[i];
		}
		sort(b.rbegin(),b.rend());
		ll ans=psum[n-1];
		for(int i=0;i<b.size();++i){
			ll fst_idx=b[i];
			if(fst_idx==0){
				if(a[0]<0){
					ans+=a[0]*-2;
				}
				break;
			}
			ll sed_idx=0;
			if(i!=b.size()-1){
				sed_idx=b[i+1]+1;
			}
			// cout<<"idx"<<fst_idx<<" "<<sed_idx<<"\n";
			ll c=psum[fst_idx]-psum[sed_idx]+a[sed_idx];
			if(c<0){
				ans+=(c*-2);
			}
			// cout<<i<<" "<<ans<<"\n";
		}
		cout<<ans<<"\n";
	} 	

	return 0;
}