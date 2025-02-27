#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> a(n,0), b(n,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		for(ll i=0;i<n;++i){
			cin>>b[i];
		}
		ll L=0, R=n-1;
		ll ans=0;
		while(L<=R){
			if(L==R){
				ans+=a[L];
				break;
			}
			if(b[L]<=b[R]){
				ans+=a[L];
				a[L+1]+=b[L];
				++L;
			}else{
				ans+=a[R];
				a[R-1]+=b[R];
				--R;
			}
		}
		
		// 체력 h를 죽이는 데 h만큼의 시간이 걸림
		// i번째 몬스터 죽이면 죽음의 축복 발동
		// i-1번째와 i+1번째에 b[i]만큼 증가
		// 끝 인덱스가 아니라면 전체 체력에는 2*b[i]증가하는거

		// 2   3 5
		// 100 5 100
		// b[i]를 무조건 작은거부터?? 처음과 끝에 제거하는게 이득일수도?
		// 1  2  3
		// 4  3  4
		
		
		
		cout<<ans<<"\n";
	} 
	return 0;
}