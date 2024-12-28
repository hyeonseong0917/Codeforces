#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long
ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b, a%b);
}
ll lcm(ll a, ll b){
	return (a/gcd(a,b))*(b/gcd(a,b))*gcd(a,b);
}
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n,x,y;
		cin>>n>>x>>y;
		ll x_cnt=n/x;
		ll y_cnt=n/y;
		// cout<<gcd(x,y);
		ll c_cnt=n/lcm(x,y);
		x_cnt-=c_cnt;
		y_cnt-=c_cnt;
		ll x_sum=0;
		ll y_sum=0;
		if(x_cnt%2==0){
			x_sum=(n+(n-x_cnt)+1)*(x_cnt/2);
		}else{
			x_sum=(n+(n-x_cnt+1))*(x_cnt/2)+(n+(n-x_cnt+1))/2;
		}
		if(y_cnt%2==0){
			y_sum=(1+y_cnt)*(y_cnt/2);
		}else{
			y_sum=((1+y_cnt)*(y_cnt/2))+(1+y_cnt)/2;
		}
		cout<<x_sum-y_sum<<"\n";
	} 
	return 0;
}