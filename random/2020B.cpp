#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> check(n+1,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
			++check[v[i]];
		}
		// A가 처음 시작
		// operate 할 수 없으면 패배
		// mx는 0으로 초기화
		// 하나의 operation에서 a[i]>=mx인 i에 대해
		// mx를 a[i]로, a[i]를 mx로
		// A가 이길 수 있는지?
		// A가 가장 큰 값을 가져가면 되지 않나?
		// 가장 큰 값의 개수가 홀수면 a가 이기고 아니면 a가 집
		sort(v.begin(),v.end());
		ll cnt=1;
		for(ll i=n-2;i>=0;--i){
			if(v[i]==v[n-1]){
				++cnt;
			}
		}
		if(cnt%2==1){
			cout<<"YES"<<"\n";
		}else{
			// 3 5 5
			// 3 3 5 5
			// 3 3 3 5 5
			// 1 1 3 3 4 5 5
			// 1 1 2 3 4 4 5 5
			bool flag=0;
			for(ll i=1;i<=n;++i){
				if(check[i]%2==1){
					flag=1;
				}
			}
			if(flag){
				cout<<"YES"<<"\n";
			}else{
				cout<<"NO"<<"\n";
			}
			
		}
	}
	return 0;
}