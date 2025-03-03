#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long
ll mod=998244353;
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		// a: 길이 n의 음이아닌정수
		// d를 만드려고함
		// d[1]=a[1]
		// d[i]=|a[i]-a[i-1]|
		// d가 주어질 떄, a를 복원해라라
		// 경우의 수가 한 개라면 그 경우의 수 출력
		// 아니라면 -1
		// a: 1 1 3 8
		// d: 1 0 2 5
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		
		bool flag=0;
		ll cur_num=v[0];
		vector<ll> ans(n,0);
		ans[0]=cur_num;
		for(ll i=1;i<n;++i){
			ll cnt=0;
			ll tmp=-1;
			for(ll j=0;j<=cur_num+v[i];++j){
				if(abs(j-cur_num)==v[i]){
					++cnt;
					tmp=j;
				}
			}
			if(cnt>=2){
				flag=1;
				break;
			}
			cur_num=tmp;
			ans[i]=cur_num;
		}
		if(flag){
			cout<<-1<<"\n";
		}else{
			for(ll i=0;i<n;++i){
				cout<<ans[i]<<" ";
			}cout<<"\n";
		}
	} 
	return 0;
}