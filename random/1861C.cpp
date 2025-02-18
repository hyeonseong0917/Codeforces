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
	while(t--){
		// a를 가지고 있다. 이것은 처음에 비어있음
		// 3개 타입의 쿼리를 수행한다.
		// 1. 정수를 고르고 수열의 끝에 붙인다. '+'
		// 2. 마지막 원소를 제거한다. '-' 빈 배열에는 못씀
		// 3. 수열이 비내림차순인지 체크. 2개보다 개수 작으면 sorted
		// sorted라면 1을 출력, 아니면 0을 출력
		string s;
		cin>>s;
		// ++1과 같은 해당 쿼리를 만들 수 있는지?
		// 두개 추가하고 비내림차순임
		// ++0-+1-+0
		// 두 개 추가
		// [2,3]

		// s의 어떤 prefix라도 +의 개수는 -개수보다 작지 않다
		ll n=s.size();
		ll p=0, h=0, seg=-1;
		bool flag=0;
		for(ll i=0;i<n;++i){
			if(flag) break;
			if(s[i]=='1' || s[i]=='0'){
				if(seg==-1){
					p+=h;
					h=0;
					seg=s[i]-'0';
					if(p<2 && s[i]=='0'){
						flag=1;
						break;
					}
					continue;
				}
				if(s[i]=='1'){
					if(seg==1){
						p+=h;
						h=0;
					}else{
						// seg=0
						if(p>1){
							flag=1;
							break;
						}
						p+=h;
						h=0;
						seg=1;
					}
				}else{
					// s[i]=='0'
					if(seg==0){
						p+=h;
						h=0;
						if(p<2){
							flag=1;
							break;
						}
					}else{
						// seg=1
						if(p>1){
							flag=1;
							break;
						}
						p+=h;
						if(p<2){
							flag=1;
							break;
						}
						h=0;
						seg=0;
					}
				}
			}else{
				if(p<=1){
					if(s[i]=='+'){
						++h;
					}else{
						--h;
					}
				}else{
					if(s[i]=='+'){
						++p;
					}else{
						--p;
					}
				}
			}
		}
		if(flag){
			cout<<"NO"<<"\n";
		}else{
			cout<<"YES"<<"\n";
		}
	} 	

	return 0;
}