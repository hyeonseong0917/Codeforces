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
		ll N,P,L,T;
		cin>>N>>P>>L>>T;
		ll x=(N-1)/7;
		++x; // x개가 해금되어 있음
		ll ans=0;
		if((x/2)*(L+2*T)>=P){
			ll l=0, r=x/2;
			ll min_num=r;
			while(l<=r){
				ll mid=(l+r)/2;
				if(mid*(L+2*T)>=P){
					min_num=min(min_num,mid);
					r=mid-1;
				}else{
					l=mid+1;
				}
			}
			ans+=min_num;
			P-=(min_num*(L+2*T));
			x-=min_num*2;
		}else{
			ans+=(x/2);
			P-=((x/2)*(L+2*T));
			x%=2;
		}
		// cout<<ans<<endl;
		if(P>0 && x>0){
			P-=(L+T);
			++ans;
		}
		if(P>0){
			ll Q=(P+(L-1))/L;
			ans+=Q;
		}
		cout<<N-ans<<"\n";

	}
	return 0;
}