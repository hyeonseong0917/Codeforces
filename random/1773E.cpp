#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=1;
	// cin>>t;
	while(t--){
		// 큐빅 블럭들. 같은 사이즈. 고유한 숫자들이 붙어있음
		// 1. 위에서 몇 개 골라서 순서 유지하면서 부리
		// 2. 합치기 순서 유지하면서
		// 작은거 위에. 큰거 아래에.
		// 가장 작은 수의 operation으로로	
		ll n;
		cin>>n;
		vector<ll> v[n+1];
		vector<ll> tmp;
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			for(ll j=0;j<a;++j){
				ll b;
				cin>>b;
				v[i].push_back(b);
				tmp.push_back(b);
			}
		}
		// split 시행횟수와 combine 시행횟수 합이 최소 되도록
		// 3 5 8
		// 9 2
		// 2 3 5 8 9
		// 0번째 원소가 top, 마지막 원소가 bottom
		sort(tmp.begin(),tmp.end());
		map<ll,ll> m;
		for(ll i=0;i<tmp.size();++i){
			m[tmp[i]]=i+1;
		}
		for(ll i=0;i<n;++i){
			for(ll j=0;j<v[i].size();++j){
				v[i][j]=m[v[i][j]];
			}
		}
		ll s=0;
		ll c=0;
		for(ll i=0;i<n;++i){
			// v[i]에서는 연속되지 않은 구간이 몇 개 있을까?
			ll k=1;
			for(ll j=1;j<v[i].size();++j){
				if(v[i][j]!=v[i][j-1]+1){
					++k;
				}
			}
			s+=k-1;
			c+=k;
		}
		--c;
		cout<<s<<" "<<c;
	} 
	return 0;
}