#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;

#define ll long long
ll mod=998244353;
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		// 1215
		// 시퀀스 a, n개의 정수들로 이루어짐
		// 모든 원소들을 같게 만들고싶음
		// 1. a에서 최소 한 번 나타나는 x를 선택
		// 2. [l,r]선택해서 제거(해당 구간엔 x 없어야함)
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> tmp;
		vector<ll> check(n+1,0);
		bool is_same=1;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			if(v[i]!=v[0]){
				is_same=0;
			}
		}
		if(is_same){
			cout<<0<<"\n";
			continue;
		}
		tmp.push_back(v[0]);
		for(ll i=1;i<n;++i){
			if(v[i]!=tmp[tmp.size()-1]){
				tmp.push_back(v[i]);
			}
		}
		for(ll i=0;i<tmp.size();++i){
			++check[tmp[i]];
		}
		for(ll i=1;i<=n;++i){
			if(check[i]){
				++check[i];
			}
		}
		--check[tmp[0]];
		--check[tmp[tmp.size()-1]];
		ll min_num=2023101800;
		for(ll i=1;i<=n;++i){
			if(!check[i]) continue;
			min_num=min(min_num,check[i]);
		}
		cout<<min_num<<"\n";
		// 1 2 3 1 2 3 1
		// 최소 구간의 개수를 갖는 숫자 선택하기
		// 
	} 
	return 0;
}