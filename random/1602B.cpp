#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long
ll c[2000+1][2000+1];
int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		// 1430
		// a[j]는 j번째 수가 나타난 횟수로 바뀜
		// k번쨰 step에서 a[x]의 값
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		ll cycle_cnt=0;
		for(ll i=0;i<=2000;++i){
			if(i==0){
				for(ll j=0;j<n;++j){
					c[i][j]=v[j];
				}
				continue;
			}
			// c[i-1][j]의 개수
			map<ll,ll> check;
			for(ll j=0;j<n;++j){
				++check[c[i-1][j]];
			}
			bool flag=0;
			for(ll j=0;j<n;++j){
				c[i][j]=check[c[i-1][j]];
				if(c[i][j]!=c[i-1][j]){
					flag=1;
				}
			}
			if(!flag){
				cycle_cnt=i-1;
				break;
			}
		}
		ll q;
		cin>>q;
		for(ll i=0;i<q;++i){
			ll a,b;
			cin>>a>>b;
			// b버째 step 후의 a번째 수의 값?
			b=min(b,cycle_cnt);
			cout<<c[b][a-1]<<"\n";
		}
	} 
	return 0;
}