#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
using namespace std;

#define ll long long

const int MAX=30+1;

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> a(n,0),b(n,0),a_psum(n,0),b_psum(n,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
			a_psum[i]=(i==0)?a[i]:a_psum[i-1]+a[i];
		}
		for(ll i=0;i<n;++i){
			cin>>b[i];
			b_psum[i]=(i==0)?b[i]:b_psum[i-1]+b[i];
		}
		ll ans=2023101800;
		for(ll i=0;i<n;++i){
			ll fst_sum=0, sed_sum=0;
			if(i+1<n){
				fst_sum=a_psum[n-1]-a_psum[i];
			}
			if(i-1>=0){
				sed_sum=b_psum[i-1];
			}
			ans=min(ans,max(fst_sum,sed_sum));
		}
		if(ans==2023101800){
			cout<<0<<"\n";
			continue;
		}
		cout<<ans<<"\n";

	}
	return 0;
}