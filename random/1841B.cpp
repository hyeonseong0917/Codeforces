#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long

ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}

int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		// beautiful 언제?
		// 앞에서 떼서 그 순서대로 뒤에 붙였을 때 비내림차순이면
		// 0개 혹은 1개로 이루어진 배열은 beautiful
		// a는 처음에 비어있음. q개의 쿼리 수행
		// i번째 쿼리에서 xi를 얻는데,
		// xi를 추가해서 a가 beautiful이라면 추가함
		// 아니라면 추가 안함
		// 각 춰리에서 추가할 수 있는지?없는지?
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> ans;
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		ans.push_back(1);
		vector<ll> p;
		p.push_back(v[0]);
		bool flag=0;
		// 0 1 2 3 4 5 6 7 8
		// 3 7 7 9 2 4 6 3 4
		// 1 1 1 1 1 0 0 1 0

		// 77932

		// 3 7 7 9 2 (4)
		// 7 7 4 (9)
		// 1 1 1 1 1
		for(ll i=1;i<n;++i){
			// v[i]를 언제 추가할 수 있을까?
			// 1. i이전에 v[i]보다 작은 값 있는지?
			// 없다면?
			if(!flag){
				if(v[i]>=p[p.size()-1]){
					p.push_back(v[i]);
					ans.push_back(1);
				}else{
					if(v[i]<=p[0]){
						flag=1;
						p.push_back(v[i]);	
						ans.push_back(1);
					}else{
						ans.push_back(0);
					}
				}
			}else{
				if(v[i]>=p[p.size()-1] && v[i]<=p[0]){
					p.push_back(v[i]);
					ans.push_back(1);
				}else{
					ans.push_back(0);
				}
			}
		}
		for(ll i=0;i<n;++i){
			cout<<ans[i];
		}cout<<"\n";
	} 	

	return 0;
}