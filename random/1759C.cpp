#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		// b[i]에 대해 a[i]혹은 a[i]-a[j]를 할당 가능
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		// 2 3 4 6 8
		// 1 4 6 7 9
		vector<ll> odd_dp(n,0), even_dp(n,0);
		// odd_dp[i]: i인덱스까지 홀수가 있는지?
		// even_dp[i]: i인덱스까지 짝수가 있는지?
		if(v[0]%2==0){
			even_dp[0]=1;
		}else{
			odd_dp[0]=1;
		}
		for(ll i=1;i<n;++i){
			if(v[i]%2==1){
				odd_dp[i]=1;
			}else{
				odd_dp[i]=odd_dp[i-1];
			}
		}
		for(ll i=1;i<n;++i){
			if(v[i]%2==0){
				even_dp[i]=1;
			}else{
				even_dp[i]=even_dp[i-1];
			}
		}
		bool flag=0;
		if(v[0]%2==1){
			// 홀수로 맞춰야함
			for(ll i=1;i<n;++i){
				if(v[i]%2==1) continue;
				if(!odd_dp[i-1]){
					flag=1;
					break;
				}
			}
		}else{
			for(ll i=1;i<n;++i){
				if(v[i]%2==0) continue;
				if(!odd_dp[i-1]){
					flag=1;
					break;
				}
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