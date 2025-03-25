#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
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
		// n,k
		// a1+a2+..+ak=n
		// lcm(a1,a2..ak)<=n/2
		ll n,k;
		cin>>n>>k;
		// k==3
		// a1+a2+a3=n
		// lcm(a1,a2,a3)<=n/2
		// 1 1 n-2

		// a1+a2=n-1
		// lcm(a1,a2)<=n/2
		// gcd가 클수록 lcm이 작아지지 않을까?
		// a1+a2=20
		// lcm(a1,a2)<=10
		// n-1짝수라면 절반절반 나누기
		// n-1홀수라면? => n은 짝수임 => 2,n-2절반,n-2절반
		
		// 14 3
		// 16 3
		// 2 7 7
		// 2 2 12
		// 4 4 8

		// 2 9 9
		// 4 8 8

		if(n%2==0){
			// 2 2 4
			if(((n-2)/2)%2==0){
				cout<<2<<" "<<(n-2)/2<<" "<<(n-2)/2<<"\n";
			}else{
				// 16 3
				// 8 4 4
				cout<<n/2<<" "<<n/4<<" "<<n/4<<"\n";
			}
		}else{
			cout<<1<<" "<<(n-1)/2<<" "<<(n-1)/2<<"\n";
		}
	} 
	return 0;
}