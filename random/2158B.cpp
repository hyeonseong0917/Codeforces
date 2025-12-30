#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n*2,0);
		vector<ll> check(n*2+1,0);
		for(ll i=0;i<n*2;++i){
			cin>>v[i];
			++check[v[i]];
		}
		ll ans=0;
		ll total_cnt=0;
		vector<ll> even_cnt;
		ll odd_cnt=0;
		for(ll i=1;i<=n*2;++i){
			if(!check[i]) continue;
			if(check[i]%2==0){
				ans+=2;
				even_cnt.pb(check[i]-1);
			}else{
				++ans;
				total_cnt+=check[i];
				odd_cnt+=check[i];
			}
			++total_cnt;
		}
		// 7 7 7 7 7 7 9 9 9 9
		if(total_cnt<n){
			// 홀수 다 채우고, 짝수 한 개씩 채웠는데도 n개를 채우기에는 모자람
			// 짝수를 최대한 홀수개씩 남기고 싶음
			// even_cnt(현재 채우는 쪽의 반대쪽에 있는 해당 수의 개수라고 생각)에는 다 홀수만 들어있음.
			// diff개를 even_cnt에서 가져와야함
			ll diff=n-total_cnt;
			if(diff%2==1){
				if(!odd_cnt){
					ans-=2;
				}
			}
		}
		// 1 1 1 1 2 2 2 2 3 3 3 3
		cout<<ans<<"\n";
	}
	return 0;
}