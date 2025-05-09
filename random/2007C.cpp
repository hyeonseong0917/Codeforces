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
		
		ll a,b,n,m;
		cin>>a>>b>>n>>m;
		// a,b,c,m
		// n과 m명의 손님
		// 바닐라쿠키 a개, 쵸콜릿쿠키 b개
		// n명의 사람들: a>b라면 --a, a<=b라면 --b
		// m명의 사람들: a>b라면 --b, a<=b라면 --a
		if(n+m>a+b){
			cout<<"NO"<<"\n";
		}else{
			if(m<=min(a,b)){
				cout<<"YES"<<"\n";
			}else{
				cout<<"NO"<<"\n";
			}
		}
	} 	

	return 0;
}