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
		// 1338
		ll n;
		cin>>n;
		if(n<4){
			cout<<n<<"\n";
			continue;
		}
		// a는 서로 다른 소수들의 곱이어야 한다
		// =2235577
		// 2:2개
		// 3:1개
		// 5:2개
		// 7:2개
		vector<pair<ll,ll>> v;
		// ll cur_num=2;
		// while(n>1 && cur_num<=n){
		// 	// cout<<n<<" "<<cur_num<<endl;
		// 	if(n%cur_num==0){
		// 		ll cnt=0;
		// 		while(!(n%cur_num)){
		// 			n/=cur_num;
		// 			++cnt;
		// 		}
		// 		v.push_back({cnt,cur_num});
		// 	}
		// 	++cur_num;
		// }
		ll c=0;
		while(n%2==0){
			n/=2;
			++c;
		}
		if(c){
			v.push_back({c,2});
		}
		for(ll i=3;i<=sqrt(n);i+=2){
			c=0;
			while(n%i==0){
				n/=i;
				++c;
			}
			if(c){
				v.push_back({c,i});
			}
		}
		if(n>2){
			v.push_back({1,n});
		}
		
		sort(v.begin(),v.end());
		ll sum=1;
		ll ans=0;
		for(ll i=0;i<v.size();++i){
			sum*=v[i].second;
		}
		// 100
		// 2:2개
		// 5:2개
		// 7:3개
		// 8:4개개
		ll cnt=0;
		for(ll i=0;i<v.size();++i){
			if(v[i].first<=cnt){
				sum/=v[i].second;
				continue;
			}
			ans+=sum*(v[i].first-cnt);
			cnt+=v[i].first-cnt;
			sum/=v[i].second;
		}
		cout<<ans<<"\n";
		// 2357 257
		// 3:1개
		// 2:2개
		// 5:2개
		// 7:2개


		// 2. 다 곱한거 / 현재수^현재개수-cnt
		// 1. ans+=다곱한거
	} 
	return 0;
}