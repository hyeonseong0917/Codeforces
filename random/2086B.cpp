#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
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
		ll n,k,x;
		cin>>n>>k>>x;
		vector<ll> v(n,0);
		ll sum=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			sum+=v[i];
		}
		if(sum*k<x){
			cout<<0<<"\n";
			continue;
		}
		// b는 n*k개의 원소가 있음. n개의 원소가 k개의 그룹 만큼 있음
		// 합이 x이상이려면?
		ll q=x/sum;
		// q개의 sum이 필요함
		ll diff=x-sum*q;
		// diff만큼을 채워야함
		ll p=0;
		ll p_cnt=0;
		for(ll i=n-1;i>=0;--i){
			if(p>=diff) break;
			p+=v[i];
			++p_cnt;
		}
		// n k x
		// p_cnt+q*n
		ll ans=n*k-(p_cnt+q*n);
		++ans;
		cout<<ans<<"\n";
	} 
	return 0;
}