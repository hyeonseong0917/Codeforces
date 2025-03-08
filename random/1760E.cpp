#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		// 최대 한 번 오퍼레이션 했을 때 인버전의 개수
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		vector<ll> zero_cnt(n,0);
		// zero_cnt[i]: i번째 인덱스부터 끝까지 0 개수
		if(v[n-1]==0){
			zero_cnt[n-1]=1;
		}
		ll cnt=0;
		for(ll i=n-2;i>=0;--i){
			if(v[i]==0){
				zero_cnt[i]=zero_cnt[i+1]+1;
			}else{
				zero_cnt[i]=zero_cnt[i+1];
				cnt+=zero_cnt[i];
			}
		}
		// 6
		// 0 1 0 0 1 0
		// 0은 최대한 앞에서, 1은 최대한 뒤에서?
		// 1 0 1 1 0 0 0 1
		// 1 1 1 1 0 0 0 1
		// 1 0 1 1 0 0 0 0
		
		ll fst_cnt=0;
		bool fst_flag=0;
		ll minus_cnt=0;
		for(ll i=0;i<n-1;++i){
			if(v[i]==0){
				if(!fst_flag){
					fst_flag=1;
					fst_cnt+=zero_cnt[i+1]-minus_cnt;
				}
			}else{
				fst_cnt+=zero_cnt[i];
				++minus_cnt;
			}
		}
		ll sed_cnt=0;
		bool sed_flag=0;
		for(ll i=n-1;i>=0;--i){
			if(v[i]==1){
				if(!sed_flag){
					sed_flag=1;
				}else{
					sed_cnt+=zero_cnt[i]+1;
				}
			}
		}
		// cout<<fst_cnt<<" "<<sed_cnt<<" "<<cnt<<endl;
		cout<<max(cnt,max(fst_cnt,sed_cnt))<<"\n";

	} 
	return 0;
}