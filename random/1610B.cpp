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
	while(t--){
		// kalindrome?
		ll n;
		cin>>n;
		// x를 골라서 몇 개 지우면 팰린드롬이 될 때
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		if(n<=2){
			cout<<"YES"<<"\n";
			continue;
		}
		// 1<=v[i]<=n
		// a가 칼린드롬인지?
		// [1,2,3]
		ll L=0, R=n-1;
		while(L<=R){
			if(v[L]!=v[R]){
				break;
			}
			++L;
			--R;
		}
		if(L>R){
			cout<<"YES"<<"\n";
			continue;
		}
		// v[L] 제거
		vector<ll> fst_tmp;
		for(ll i=0;i<n;++i){
			if(v[L]==v[i]) continue;
			fst_tmp.push_back(v[i]);
		}
		// v[R] 제거
		vector<ll> sed_tmp;
		for(ll i=0;i<n;++i){
			if(v[R]==v[i]) continue;
			sed_tmp.push_back(v[i]);
		}
		bool fst_flag=0, sed_flag=0;
		for(ll i=0;i<fst_tmp.size();++i){
			if(fst_tmp[i]!=fst_tmp[fst_tmp.size()-1-i]){
				fst_flag=1;
				break;
			}
		}
		for(ll i=0;i<sed_tmp.size();++i){
			if(sed_tmp[i]!=sed_tmp[sed_tmp.size()-1-i]){
				sed_flag=1;
				break;
			}
		}
		if(fst_flag && sed_flag){
			cout<<"NO"<<"\n";
		}else{
			cout<<"YES"<<"\n";
		}
	} 	

	return 0;
}