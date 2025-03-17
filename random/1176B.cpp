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
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
			v[i]%=3;
		}
		// 3으로 나누어 떨어지는 수의 개수를 최대로
		ll ans=0;
		ll fst_num=0, sed_num=0;
		for(ll i=0;i<n;++i){
			if(v[i]==0){
				++ans;
				continue;
			}
			if(v[i]==1){
				++fst_num;
			}else{
				++sed_num;
			}
		}
		ll min_num=min(fst_num,sed_num);
		cout<<ans+min_num+(fst_num-min_num)/3+(sed_num-min_num)/3<<"\n";
	} 

	return 0;
}