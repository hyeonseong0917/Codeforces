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
		// 모든 원소가 0이 되면 exploded
		// a[i]-i 혹은 a[i]-(n-i+1)
		// 모든 원소를 0으로 만드는게 가능한지
		ll n;
		cin>>n;
		vector<ll> v(n+1,0);
		for(ll i=1;i<=n;++i){
			cin>>v[i];
		}
		// 1 2 3 4
		// 3 6 6 3

		// 1  2  3  4  5  6 7 8 9 10 11 12 13 14
		// 14 13 12 11 10 9 8 7 6 5  4   3  2  1
		// 한 번의 operation: 모든 배열의 원소 -i 혹은 -(n-i+1)

		// a[1]=x+n*y
		// a[2]=2x+(n-1)*y
		// a[3]=3x+(n-2)*y
		// a[1]-a[2]=-x+y=y-x
		// x=y-diff
		// a[1]=y-diff+n*y
		// a[1]+diff=(n+1)*y
		ll diff=v[1]-v[2];
		ll y=-1;
		ll x=-1;
		if((v[1]+diff)%(n+1)==0){
			y=(v[1]+diff)/(n+1);
			x=y-diff;
		}
		// cout<<x<<" "<<y<<endl;
		if(x<0 || y<0){
			cout<<"NO"<<"\n";
			continue;
		}
		bool flag=0;
		for(ll i=2;i<=n;++i){
			if(v[i]!=i*x+(n-i+1)*y){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<"NO"<<"\n";
		}else{
			cout<<"YES"<<"\n";
		}

	} 	
	return 0;
}