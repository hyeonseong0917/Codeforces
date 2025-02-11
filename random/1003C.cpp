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
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		for(ll i=0;i<m;++i){
			cin>>b[i];
		}
		bool flag=0;
		sort(b.begin(),b.end());
		a[0]=min(a[0],b[0]-a[0]);
		for(ll i=1;i<n;++i){
			if(a[i]<a[i-1]){
				// replace
				// a[i-1]보다 큰 최소의 값으로
				// b[j]-a[i]
				ll L=0, R=m-1;
				ll min_num=2023101800;
				while(L<=R){
					ll mid=(L+R)/2;
					if(b[mid]-a[i]>=a[i-1]){
						min_num=min(min_num,b[mid]-a[i]);
						R=mid-1;
					}else{
						L=mid+1;
					}
				}
				if(min_num==2023101800){
					flag=1;
					break;
				}
				a[i]=min_num;
			}else{
				// a[i]>=a[i-1]
				// a[i]=(b[mid]-a[i])를 만들기 위해
				// a[i-1]보다 큰 최소의 값
				ll L=0, R=m-1;
				ll min_num=2023101800;
				while(L<=R){
					ll mid=(L+R)/2;
					if(b[mid]-a[i]>=a[i-1]){
						min_num=min(min_num,b[mid]-a[i]);
						R=mid-1;
					}else{
						L=mid+1;
					}
				}
				if(min_num==2023101800) continue;
				a[i]=min(a[i],min_num);
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