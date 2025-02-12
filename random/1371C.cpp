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
		// 1553
		// a개의 바닐라쿠키, b개의 초콜릿 쿠키 가지고있음
		// n명 first type, m명 second type
		// 각 손님은 쿠키의 타입을 선택함
		// first type: v>c => v 선택, 아니면 c선택
		// second type: v>c => c선택, 아니면 v선택 
		ll a,b,n,m;
		cin>>a>>b>>n>>m;
		// a b n m
		// 2 2 1 2
		// 


	} 	

	return 0;
}