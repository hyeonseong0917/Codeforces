#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll k;
		cin>>k;
		ll R=k*2;
		ll L=1;
		ll ans=R;
		// 가장 최소인 ans을 구한다
		while(L<=R){
			ll mid=(L+R)/2;
			ll cur_num=mid-(ll)sqrt(mid);
			// cout<<L<<" "<<R<<" "<<mid<<" "<<cur_num<<endl;
			if(cur_num<k){
				L=mid+1;
			}else{
				// cout<<L<<" "<<R<<" "<<cur_num<<endl;
				if(cur_num==k){
					ans=min(ans,mid);
				}
				R=mid-1;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}