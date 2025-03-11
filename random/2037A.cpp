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
		// 초기 점수 0
		// 인덱스 i<j를 선택.
		// 인덱스는 한 번 사용하면 사용 불가
		// a[i]=a[j]여야함
		// 조건 만족시 점수 +1
		// 점수를 최대화하도록
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> check(20+1);
		for(ll i=0;i<n;++i){
			cin>>v[i];
			++check[v[i]];
		}
		ll ans=0;
		for(ll i=1;i<=n;++i){
			ans+=check[i]/2;
		}
		cout<<ans<<"\n";
	} 
	return 0;
}