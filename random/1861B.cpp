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
		// a와 b라는 같은 길이의 문자열 주어짐
		// 0과 1로 이루어짐
		// 모두 0으로 시작해서 1로 끝남
		// operation 마음껏
		// L,R선택 s[L]=s[R]인
		// 하나의 문자열에서 같은 두 문자에 대해
		// 그 사이에 있는 값을 해당 문자로 교체함

		// 두 문자열을 동일하게 만들 수 있는지?
		// n^2가능
		string a,b;
		cin>>a;
		cin>>b;
		ll n=a.size();
		if(n==2 || a.compare(b)==0){
			cout<<"YES"<<"\n";
			continue;
		}
		// 01010001
		// 01110001
		// 01110101

		// 000111
		// 000111
		// 011111
		// 001001
		bool flag=0;
		for(ll i=0;i<n-1;++i){
			if(a[i]==b[i] && a[i]=='0'){
				// i+1 ~ n-1까지 다 1로 만들기 가능?
				if(a[i+1]=='1' && b[i+1]=='1'){
					flag=1;
					break;
				}
			}
		}
		if(flag){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
	} 	

	return 0;
}