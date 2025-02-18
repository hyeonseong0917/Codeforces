#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long

ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}

int main() {
	// your code goes here
	int t=1;
	cin>>t;
	string ans="";
	while(t--){
		// s[1]은 명시적으로 주어짐
		// s[i]를 얻기 위해서는 s[i-1]로부터 제거되어야
		// s[i]가 최소가 되도록
		string s;
		cin>>s;
		ll n;
		cin>>n;
		ll ss=s.size();
		ll cnt=0;
		ll sum=0;
		ll mod=0;
		while(1){
			sum+=ss;
			++cnt;
			if(sum>=n){
				mod=ss;
				mod-=(sum-n);
				break;
			}
			--ss;
		}
		// dacb -> acb -> ab ->a
		// 매 라운드마다 어떤 문자를 제거해야 할까?
		// 앞에서부터 s[i]>s[i+1]인 문자?
		// 없다면 모두 s[i]<=s[i+1]인 상태이므로 가장 뒤에꺼 삭제
		// 전체 문자열의 길이: 1+2+...+n
		
		// dacb
		// 1010

		// cdacb
		// 01010

		// bcacb -> bacb -> acb -> ab ->a
		// 01010

		// cnt번째 라운드
		// mod번째 수(1 based)

		// cnt-1번 제거를 한 수임 cnt번째 라운드의 수는

		// s의 cnt-1번 제거한 수는 어떤 수일까?
		// 앞에서 i번째 수 만약 제거 했다면? i-1번째 수와
		// i+1번째 수를 비교해야함. i-1번째 수가 더 크다면
		// i-1번째 수 제거해야

		// [b,c <-a
		--cnt;
		stack<char> st;
		ss=s.size();
		ll idx=0;
		while(idx<ss){
			if(cnt==0){
				st.push(s[idx++]);
				continue;
			}
			if(st.empty()){
				st.push(s[idx++]);
			}else{
				if(st.top()>s[idx]){
					st.pop();
					--cnt;
				}else{
					st.push(s[idx++]);
				}
			}
		}
		while(cnt){
			st.pop();
			--cnt;
		}
		// cout<<st.size()<<"\n";
		string S="";
		while(!st.empty()){
			S+=st.top();
			st.pop();
		}
		reverse(S.begin(),S.end());
		ans+=S[mod-1];
		
	} 	
	cout<<ans;

	return 0;
}