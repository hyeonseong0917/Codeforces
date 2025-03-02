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
		// 1137
		// 증가하지 않는다
		// 54321
		// 12345
		// 언제 대칭일까??

		// 53311

		//     .
		// . . .
		// . . . . .
		// . . . .
		// . . . . 

		// .
		// . .
		// . . .
		// . . . .
		// . . . . .
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		if(n==1){
			if(v[0]==1){
				cout<<"YES"<<"\n";
			}else{
				cout<<"NO"<<"\n";
			}
			continue;
		}
		bool flag=0;
		for(ll i=0;i<n-1;++i){
			if(v[i]<i+1) break;
			ll h=v[i]-(i+1);
			ll idx=2023101800;
			ll L=i+1, R=n-1;
			while(L<=R){
				ll mid=(L+R)/2;
				if(v[mid]<i+1){
					idx=min(idx,mid);
					R=mid-1;
				}else{
					L=mid+1;
				}
			}
			if(idx==2023101800){
				if(n-1-(i+1)+1!=h){
					flag=1;
					break;
				}
			}else{
				--idx;
				if(idx-(i+1)+1!=h){
					flag=1;
					break;
				}
			}
		}
		if(flag){
			cout<<"NO"<<"\n";
		}else{
			cout<<"YES"<<"\n";
		}
	}
	return 0;
}