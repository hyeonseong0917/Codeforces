#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	cin>>t;
	while(t--){
		ll n,x;
		cin>>n>>x;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		// v[i]+x*y가 cur_num을 만들 수 있는지?
		// (cur_num-v[i])%x==0인지?
		// cur_num>=v[i] 여야함
		// cur_num<v[i]인데, tmp에서도 못찾았으면 ㅈㅈ
		// v[i]에서 못찾았으면, tmp에서 찾기
		// tmp에서도 못찾았으면 tmp에 넣고 i다음원소 넘어가기
		ll cur_num=0;
		ll idx=0;
		map<ll,ll> tmp;
		while(idx<n){
			if(cur_num<v[idx]){
				ll cur_mod=cur_num%x;
				if(tmp[cur_mod]){
					// tmp에서 끌어써서 cur_num일단 해결하기
					--tmp[cur_mod];
					++cur_num;
				}else{
					break;
				}
			}else{
				// cur_num>=v[idx]
				if((cur_num-v[idx])%x==0){
					++idx;
					++cur_num;
				}else{
					// tmp에서 끌어써서 cur_num일단 해결하기
					if(tmp[cur_num%x]){
						--tmp[cur_num%x];
						++cur_num;
					}else{
						// 해결 못함 idx를 tmp에 넣고 ++idx해야함
						++tmp[v[idx]%x];
						++idx;
					}
					
				}
				// cout<<idx<<" "<<cur_num<<endl;
			}
		}
		// 마지막으로 tmp에 cur_num 있는지?
		// tmp에는 cur_num보다 작은 값의 키밖에 없는데
		while(1){
			if(tmp[cur_num%x]){
				--tmp[cur_num%x];
				++cur_num;
			}else{
				break;
			}
		}
		cout<<cur_num<<"\n";
	}
	return 0;
}