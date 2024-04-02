#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n,q;
		cin>>n>>q;
		vector<ll> v(n,0);
		//dp[i]: i인덱스까지 1의 개수
		vector<ll> one_cnt(n,0);
		vector<ll> psum(n,0); //1 제외한 sum
		ll cur_num=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		if(v[0]==1){
			++one_cnt[0];
		}else{
			psum[0]=v[0];
		}
		for(ll i=1;i<n;++i){
			one_cnt[i]=one_cnt[i-1];
			psum[i]=psum[i-1];
			if(v[i]==1){
				++one_cnt[i];
				// cout<<i<<" "<<one_cnt[i]<<endl;
			}else{
				psum[i]+=v[i];
			}
		}
		for(ll i=0;i<q;++i){
			ll a,b;
			cin>>a>>b;
			--a;
			--b;
			ll cur_sum=psum[b];
			ll cur_one_cnt=one_cnt[b];
			// cout<<cur_one_cnt<<"\n";
			if(a!=0){
				cur_sum-=psum[a-1];
				cur_one_cnt-=one_cnt[a-1];
			}
			ll cur_rest_cnt=(b-a+1)-cur_one_cnt;
			// cout<<cur_sum<<" "<<cur_rest_cnt<<" "<<cur_one_cnt<<"\n";
			if(cur_sum-cur_rest_cnt>=cur_one_cnt && a!=b){
				cout<<"YES"<<"\n";
			}else{
				cout<<"NO"<<"\n";
			}
		}
	}
	
	return 0;
}