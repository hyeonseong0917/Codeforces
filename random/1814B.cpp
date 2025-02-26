#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long

ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll a,b;
		cin>>a>>b;
		// 한 번의 action에서 셋 중 하나
		// 1. xpos jump
		// 2. ypos jump
		// 3. 다리길이 +1
		// 0,0에서 a,b까지 최소 오퍼레이션 수로?
		// 3 7
		ll c=gcd(a,b);
		ll tmp_a=min(a,b);
		ll tmp_b=max(a,b);
		a=tmp_a;
		b=tmp_b;
		ll ans=0;
		if(a==1 && b==1){
			cout<<2<<"\n";
			continue;
		}
		// a<=b
		// 4 8
		// 7 8
		// 7 7
		// 6 6
		cout<<ans<<"\n";
	} 
	return 0;
}