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
	// cin>>t;
	while(t--){
		// M or from 0 to 3 "X" Sto "S,L"
		ll n;
		cin>>n;
		vector<string> a[4+1],b[4+1];
		for(ll i=0;i<n;++i){
			string tmp="";
			cin>>tmp;
			ll ts=tmp.size();
			a[ts].push_back(tmp);
		}
		for(ll i=0;i<n;++i){
			string tmp="";
			cin>>tmp;
			ll ts=tmp.size();
			b[ts].push_back(tmp);
		}
		ll ans=0;
		// M, S, L, XS, XL, XXS, XXL, XXXS, XXXL
		// 길이 별 비교? => 주효함
		for(ll i=1;i<=4;++i){
			if(a[i].empty()) continue;
			// 길이 i에 대해
			map<string,ll> a_check, b_check;
			// A: M,M,S,L,L
			// B: S,M,L,L,L

			// M S
			// L L
			// A를 B로 만들고 싶음
			// 이미 같은 건 제거하고 싶음
			// 남은거+1 /2
			for(ll j=0;j<a[i].size();++j){
				++a_check[a[i][j]];
			}
			for(ll j=0;j<b[i].size();++j){
				++b_check[b[i][j]];
			}
			ll ts=a[i].size();
			// a와 b에 둘 다 있는거
			ll cnt=0;
			for(ll j=0;j<ts;++j){
				if(b_check[a[i][j]]){
					--b_check[a[i][j]];
				}else{
					++cnt;
				}
			}
			// ans+=(cnt+1)/2;
			ans+=cnt;
		}
		cout<<ans<<"\n";
		
	} 
	return 0;
}
