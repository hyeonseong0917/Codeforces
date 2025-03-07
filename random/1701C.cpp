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
	int t=1;
	cin>>t;
	while(t--){
		// n명의 작업자와 m개의 일들이 있음
		// 작업자는 1에서 n까지 번호가 붙어있음
		// 각 작업 i는 값 a[i]를 가짐 -> 작업자의 인덱스?값?
		// 적합한 작업자였다면 1시간 걸리고, 아니면 2시간 걸림
		// 가장 빠르게 끝나는 방법은
		
		// 2 4
		// 0 1 2 3
		// 1 2 1 2
		ll n,m;
		cin>>n>>m;
		vector<ll> check(n+1,0);
		for(ll i=0;i<m;++i){
			ll a;
			cin>>a;
			++check[a];
		}
		vector<ll> v;
		ll total_work=0;
		for(ll i=1;i<=n;++i){
			v.push_back(check[i]);
			total_work+=check[i];
		}
		sort(v.begin(),v.end());
		// 4 4
		// 1 2 1 2

		// 0 1 2 3
		// 2 2 0 0
		// 전체 일의 개수: 4

		// T일에 끝난다면
		// 사람번호 0인 사람은 몇개의 일 가능?
		// T>=v[i]라면 v[i]+(T-v[i])/2
		// T<v[i]라면 T
		// 2인덱스는 몇 개의 일을 할 수 있는지?
		ll L=1, R=2*m;
		ll ans=2*m;
		while(L<=R){
			ll mid=(L+R)/2;
			ll cur_work=0;
			for(ll i=0;i<v.size();++i){
				if(mid>=v[i]){
					cur_work+=v[i]+(mid-v[i])/2;
				}else{
					cur_work+=mid;
				}
			}
			if(cur_work>=total_work){
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