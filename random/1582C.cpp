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
		// string s, 길이 n인
		// 팰린드롬
		// 소문자 하나 골라서 몇 개 삭제함
		// 최소한으로 삭제하는 경우의 수?
		ll n;
		cin>>n;
		string s;
		cin>>s;
		// 하나 골라서 어떤 경우에도 팰린드롬 만들지 못한다면
		// -1
		// abcaacab
		// 1. 원래 팰린드롬인지?
		// 2. a지우기로 팰린드롬 만들기 가능?
		// 3. b지우기로 팰린드롬 가능..?
		// L과 R 보면서 둘 다 지우려는 문자면 pass
		// 한 쪽만 지우려는 문자면 지우면서 거
		ll L=0, R=n-1;
		bool flag=0;
		while(L<=R){
			if(s[L]!=s[R]){
				flag=1;
				break;
			}
			++L;
			--R;
		}
		if(!flag){
			cout<<0<<"\n";
			continue;
		}
		ll ans=2023101800;
		for(ll i=0;i<26;++i){
			char c='a'+i;
			L=0, R=n-1;
			ll cnt=0;
			bool f=0;
			while(L<=R){
				if(s[L]==s[R]){
					++L;
					--R;
					continue;
				}
				// s[L]!=s[R]
				if(s[L]!=c && s[R]!=c){
					f=1;
					break;
				}
				if(s[L]==c){
					++L;
					++cnt;
				}else if(s[R]==c){
					--R;
					++cnt;
				}
			}
			if(f) continue;
			ans=min(ans,cnt);
		}
		if(ans==2023101800){
			cout<<-1<<"\n";
		}else{
			cout<<ans<<"\n";
		}
	} 

	return 0;
}