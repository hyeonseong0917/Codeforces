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
		// n개의 정수가 써져있음
		// 다 1이다
		// A부터 시작해서 각 플레이어는 최소2개의 같은 정수 골라서
		// 다 삭제하고 그들의 sum을 추가함
		// 만약 진행할 수 없다면 그 플레이어는 이긴다
		ll n;
		cin>>n;
		if(n-2>2){
			cout<<"Alice"<<"\n";
		}else{
			// n<=4
			cout<<"Bob"<<"\n";
		}
	} 	

	return 0;
}