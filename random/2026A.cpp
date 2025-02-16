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
		ll x,y,k;
		cin>>x>>y>>k;
		ll m=min(x,y);
		cout<<0<<" "<<0<<" "<<m<<" "<<m<<"\n";
		cout<<0<<" "<<m<<" "<<m<<" "<<0<<"\n";


	} 	

	return 0;
}