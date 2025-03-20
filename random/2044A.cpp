#include <iostream>
#include <algorithm>
#include <vector>
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
		ll n;
		cin>>n;
		// a+b==n인 pair의 수
		cout<<n-1<<"\n";
		
	} 
	return 0;
}