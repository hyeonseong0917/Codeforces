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
		ll n,x;
		cin>>n>>x;
		// 사이즈가 k인 이모트 삼각형을 보내고 싶음
		// x개를 보내면 즉시 밴당함
		if(n==1){
			cout<<1<<"\n";
			continue;
		}

		if((n*(n+1))/2>=x){
			ll L=1, R=n;
			ll ans=n;
			while(L<=R){
				ll mid=(L+R)/2;
				if((mid*(mid+1))/2>=x){
					R=mid-1;
					ans=min(ans,mid);
				}else{
					L=mid+1;
				}
			}
			cout<<min(n,ans)<<"\n";
		}else{
			x-=(n*(n+1))/2;
			// n-1,n-2,n-3...1
			// n-1부터 k개 선택
			ll L=1, R=n-1;
			ll ans=n-1;
			while(L<=R){
				// mid개 선택하면?
				ll mid=(L+R)/2;
				// [n-1,n-mid]
				ll sum=((n-1)*n)/2-((n-mid)*(n-mid+1))/2+n-mid;
				if(sum>=x){
					ans=min(ans,mid);
					R=mid-1;
				}else{
					L=mid+1;
				}
			}
			ans+=n;
			cout<<ans<<"\n";
		}
		
	} 

	return 0;
}