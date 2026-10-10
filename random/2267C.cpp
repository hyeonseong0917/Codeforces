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
	
	// 일단 30만보다 작은 모든 소수들을 찾아보자
	vector<ll> tmp;
	// check[i]=1: 소수가아님
	vector<ll> check(300000+1,0);
	for(ll i=2;i*i<=300000;++i){
		if(check[i]) continue;
		for(ll j=i*i;j<=300000;j+=i){
			check[j]=1;
		}
	}
	for(ll i=2;i<=300000;++i){
		if(check[i]) continue;
		tmp.push_back(i);
	}
	while(t--){
		// 숫자 x를 가지는데, 코인을 훔칠 때 씀
		// 1. a[i]>0이면서 gcd(a[i],x)가 1이 아닌, 서로소가 아닌 인덱스 i를 고름
		// 2. gcd(a[i],x)를 구함. 이거를 g라고 정의함
		// 나는 g만큼얻고, a[i]는 g만큼적어짐
		// 3. x를 g로 설정하고, 다시 코인을 찾아 나섬
		// 훔칠 수 있는 최대 코인의 수
		ll n,x;
		cin>>n>>x;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		// p[i]: 소인수 i를 가져간다면 어떤 최종 보상을 얻을 수 있는지를 기록
		
		// x의 소인수 구하기
		vector<ll> x_tmp;
		ll c=x;
		for(ll i=0;i<tmp.size();++i){
			if(tmp[i]*tmp[i]>c) break;
			if(c%tmp[i]==0){
				x_tmp.push_back(tmp[i]);
				while(c%tmp[i]==0){
					c/=tmp[i];
				}
			}
		}
		if(c>1){
			x_tmp.push_back(c);
		}
		ll xs=x_tmp.size();
		// p[i]: x_tmp[i]를 가장 작은 소인수로 했을 떄의 결과값
		vector<ll> p(xs, 0);

		for(ll i=0; i<n; ++i){
			for(ll j=0; j<xs; ++j){
				if(v[i] % x_tmp[j] == 0){
					p[j] += v[i]; // 수정
				}
			}
		}

		ll ans = 0;
		for(ll i=0; i<xs; ++i){
			ans = max(ans, p[i]); // 수정
		}
		// vector<ll> p(x+1,0);
		// for(ll i=0;i<n;++i){
		// 	for(ll j=0;j<x_tmp.size();++j){
		// 		if(v[i]%x_tmp[j]==0){
		// 			p[x_tmp[j]]+=v[i];
		// 		}
		// 	}
		// }
		
		// ll ans=0;
		// for(ll i=0;i<x_tmp.size();++i){
		// 	ans=max(ans,p[x_tmp[i]]);
		// }
		
		cout<<ans<<"\n";
	} 	

	return 0;
}