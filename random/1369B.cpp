#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
 
#define ll long long
ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
ll lcm(ll a, ll b){
	return (a*b)/gcd(a,b);
}
int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		// messy string을 발견함
		// string s는 길이 n의 바이너리 스트링임
		// 하나의 move에 연속한 두 개의 문자 고를 수 있음
		// 만약 10이라면 둘 중 하나를 지울 수 있음
		ll n;
		cin>>n;
		string s;
		cin>>s;
		// 가장 클린한 문자열을 만들어라
		// 클린하다는 것은 일단 길이가 짧다는 것
		// 그 다음 사전순으로 빠른것
		// 10을 골라서 하나를 지울 수 있음
		// (1) 11001101
		// (2) 01001101
		// 10을 발견하면 어떻게 해야>
		// 10이 아니라면 st에 넣기?
		// st의 top이 1이라면 0으로 바꾸기
		// st의 top이 0이거나 empty라면 1넣기
		// [1,
		// 0이라면 st의 top 비교,1이라면 계속 pop
		stack<char> st;
		for(ll i=0;i<s.size();++i){
			if(st.empty()){
				st.push(s[i]);
			}else{
				char cur_char=s[i];
				if(cur_char=='1'){
					st.push(s[i]);
				}else{
					bool flag=0;
					while(!st.empty()){
						if(st.top()=='1' || st.top()=='2'){
							flag=1;
							st.pop();
						}else{
							break;
						}
					}
					// 1을넣을까? 0을넣을까?
					if(i==n-1){
						st.push('0');
					}else{
						// st에는 000상태임
						// 11000
						if(flag){
							st.push('2');
						}else{
							st.push(s[i]);
						}
						
					}
				}
			}
		}
		string ans="";
		while(!st.empty()){
			char c=st.top();
			if(c=='2'){
				ans+='0';
			}else{
				ans+=c;
			}
			st.pop();
		}
		reverse(ans.begin(),ans.end());
		cout<<ans<<"\n";

	} 
	return 0;
}