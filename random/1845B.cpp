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
		// A와B와C는 처음에 A에 있다
		// 
		ll xa,ya,xb,yb,xc,yc;
		cin>>xa>>ya;
		cin>>xb>>yb; // b의 집 위치
		cin>>xc>>yc; // c의 집 위치
		// 최단거리로 이동했을 때 b와 c가 겹치는 경로의 최대길이
		// 현재 둘 다 xa와 ya에 있음
		ll ans=0;
		ll y_diff=min(abs(ya-yc),abs(ya-yb));
		if((yb<ya && ya<yc) || (yc<ya && ya<yb)){
			y_diff=0;
		}
		ll x_diff=0;
		if((xb<xa && xa<xc) || (xc<xa && xa<xb)){
			x_diff=0;
		}else{
			x_diff=min(abs(xa-xb),abs(xa-xc));
		}
		cout<<y_diff+x_diff+1<<"\n";

	} 	

	return 0;
}