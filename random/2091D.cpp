#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int o=1;
	cin>>o;
	while(o--){
		ll n,m,k;
		cin>>n>>m>>k;
		// ll c=(k+n-1)/n;
		// if(c<=3){
		// 	cout<<1<<"\n";
		// }else{
		// 	// c>4
		// 	ll L=1, R=m;
		// 	ll ans=R;
		// 	while(L<=R){
		// 		ll mid=(L+R)/2;
		// 		// 최대 mid개로 k명 커버 가능?
		// 		ll c=m/(mid+1);
		// 		ll d=m-c*(mid+1);
				
		// 		// cout<<mid<<" "<<c<<" "<<n<<"\n";
		// 		if(mid*c*n+d*n>=k){
		// 			ans=min(ans,mid);
		// 			R=mid-1;
		// 		}else{
		// 			L=mid+1;
		// 		}
		// 	}
		// 	cout<<ans<<"\n";
		// }
		// c>4
		ll L=1, R=m;
		ll ans=R;
		while(L<=R){
			ll mid=(L+R)/2;
			// 최대 mid개로 k명 커버 가능?
			ll c=m/(mid+1);
			ll d=m-c*(mid+1);
			
			// cout<<mid<<" "<<c<<" "<<n<<"\n";
			if(mid*c*n+d*n>=k){
				ans=min(ans,mid);
				R=mid-1;
			}else{
				L=mid+1;
			}
		}
		cout<<ans<<"\n";
	} 

	return 0;
}