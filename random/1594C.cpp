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
		// 1603
		// 최소의 operation으로 모든 문자가 c와 같게 하고싶음
		// 하나의 oper에서 숫자 x를 선택하고,
		// x로 나누어 떨어지지 않는 모든 i에 대해 s[i]를 c로
		// i%x!=0
		// 1<=x<=n
		// 최소 수의 operation을 구해라
		ll n;
		char c;
		cin>>n;
		cin>>c;
		string s;
		cin>>s;
		bool flag=0;
		for(ll i=0;i<s.size();++i){
			if(s[i]!=c){
				flag=1;
				break;
			}
		}
		if(!flag){
			cout<<0<<"\n";
			continue;
		}
		// 최대 2번의 연산
		// 1. n선택하면 1~n-1의 모든 수들은 c로 됨
		// 2. n-1선택하면 n도 c로됨

		// 1. 1~n-1까지 모든 수가 c인지?
		// bcb
		// bbcbbc

		// bbbbcn
		vector<ll> ans;
		// x를 골랐을때, 기존의 c는 패스하고
		// x는 2,3,5,7,
		for(ll i=2;i<=n;++i){
			bool flag=1;
			for(ll j=1;i*j<=n;++j){
				flag&=(s[i*j-1]==c);
			}
			if(flag){
				ans.push_back(i);
				break;
			}
		}

		ll as=ans.size();
		if(as==1){
			cout<<1<<"\n";
			cout<<ans[0]<<"\n";
			continue;
		}
		ans.push_back(n-1);
		ans.push_back(n);
		as=ans.size();	
		cout<<as<<"\n";
		for(ll i=0;i<as;++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";
	} 

	return 0;
}