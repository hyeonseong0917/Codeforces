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
		ll a,b;
		cin>>a>>b;
		cout<<2<<"\n";
		cout<<a-1<<" "<<1<<"\n";
		cout<<a<<" "<<b<<"\n";
	} 	

	return 0;
}