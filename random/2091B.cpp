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
		// n명의 학생들이 듣는중
		// i번째 학생의 스킬은 a[i]임
		// 그 팀의 강함을 strength가 최소 x이상일 경우 판단
		// 팀 멤버 수 * 최소의 스킬 값
		// 가능한 강한 팀의 최대 수
		ll n,x;
		cin>>n>>x;
		vector<ll> v(n,0);
		map<ll,ll> check;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			++check[v[i]];
		}
		sort(v.begin(),v.end());
		// 6 4
		// 4 5 3 3 2 6
		// 2 3 3 4 5 6
		ll ans=0;
		ll idx=n-1;
		for(ll i=0;i<n;++i){
			if(v[i]>=x){
				ans=n-1-i+1;
				idx=i-1;
				break;
			}
		}
		// 0~idx는 x보다 작음
		ll cur_num=1;
		ll cnt=1;
		for(ll i=idx;i>=0;--i){
			cur_num=cnt*v[i];
			if(cur_num>=x){
				++ans;
				cnt=1;
			}else{
				++cnt;
			}
		}
		// if(cur_num>=x){
		// 	++ans;
		// }

		cout<<ans<<"\n";

	} 

	return 0;
}