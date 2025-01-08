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
	ll o=1;
	cin>>o;
	while(o--){
		ll n;
		cin>>n;
		ll L=2;
		ll R=(ll)pow(10,18);
		R=sqrt(2*R)+1;
		ll ans=R*2;
		while(L<=R){
			ll mid=(L+R)/2;
			ll kc2=mid*(mid-1)/2;
			// cout<<kc2<<endl;
			if(kc2<=n && n<=kc2+mid){
				ans=min(ans,mid+n-kc2);
				L=mid+1;
			}else{
				if(kc2<n){
					L=mid+1;
				}else{
					R=mid-1;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}