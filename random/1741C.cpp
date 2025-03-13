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
		// 1430
		// n개의 양수로 이루어진 배열
		// 시퀀스 a를 다음 세그먼트로 자르려고 한다
		// 각 원소는 정확히 한 세그먼트에
		// 각 세그먼트 원소의 합은 동일해야 한다
		// 가장 긴 세그먼트의 길이를 최소로 하고싶음
		// 합을 가능한 한 크게하는게 유리한가?
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> psum(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
			psum[i]=(i==0)?v[i]:psum[i-1]+v[i];
		}
		ll ans=n;
		for(ll i=0;i<n-1;++i){
			ll cur_num=psum[i];
			ll L=i+1;
			ll R=i+1;
			bool flag=0;
			ll cur_psum;
			ll max_len=i+1;
			while(R<n){
				cur_psum=psum[R]-psum[L]+v[L];
				if(cur_psum==cur_num){
					max_len=max(max_len,R-L+1);
					L=R+1;
					++R;
				}else if(cur_psum>cur_num){
					flag=1;
					break;
				}else{
					++R;
				}
			}
			if(cur_psum!=cur_num){
				flag=1;
			}
			if(!flag){
				ans=min(ans,max_len);
			}
		}
		cout<<ans<<"\n";
		
	} 

	return 0;
}