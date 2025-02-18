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
		// n을 서로 다른 양의 정수인 x,y,z의 합으로
		// 어떤 것도 3으로 나누어지면 안됨됨
		ll n;
		cin>>n;
		// %1 %2
		// 1 2 3
		if(n<=6){
			cout<<"NO"<<"\n";
			continue;
		}
		// 1 2 x
		// 1 4 x
		// 2 5 x
		bool flag=0;
		if((n-3)%3!=0 && n-3!=1 && n-3!=2){
			cout<<"YES"<<"\n";
			cout<<1<<" "<<2<<" "<<n-3<<"\n";
			continue;
		}
		if((n-5)%3!=0 && n-5!=1 && n-5!=4){
			cout<<"YES"<<"\n";
			cout<<1<<" "<<4<<" "<<n-5<<"\n";
			continue;
		}
		if((n-7)%3!=0 && n-7!=2 && n-7!=5){
			cout<<"YES"<<"\n";
			cout<<2<<" "<<5<<" "<<n-7<<"\n";
			continue;
		}
		cout<<"NO"<<"\n";
	} 	

	return 0;
}