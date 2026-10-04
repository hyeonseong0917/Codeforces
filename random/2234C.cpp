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
		ll n;
		cin>>n;
		vector<ll> h(n,0);
		for(ll i=0;i<n;++i){
			cin>>h[i];
		}
		vector<ll> ans(n,0);
		for(ll i=0;i<n;++i){
			vector<ll> v(n,0);
			if(i==0){
				i=n;
			}
			vector<ll> l_dp(n,0), r_dp(n,0);
			ll R=i+1;
			r_dp[R%n]=h[i%n];
			++R;
			while((R%n)!=i%n){
				ll idx=R%n;
				ll c=(idx-1+n)%n;
				if(h[c]<r_dp[c]){
					r_dp[idx]=r_dp[c];
				}else{
					r_dp[idx]=h[c];
				}
				++R;
				// cout<<R<<endl;
			}
			ll L=i-1;
			l_dp[(L+n)%n]=h[(L+n)%n];
			--L;
			while(((L+n)%n)!=i%n){
				ll idx=(L+n)%n;
				if(h[idx]<l_dp[(idx+1)%n]){
					l_dp[idx]=l_dp[(idx+1)%n];
				}else{
					l_dp[idx]=h[idx];
				}
				--L;
			}
			ll sum=0;
			for(ll j=0;j<n;++j){
				if(i==j) continue;
				// cout<<r_dp[j]<<" "<<l_dp[j]<<"\n";
				sum+=min(r_dp[j],l_dp[j]);
			}
			if(i==n){
				i=0;
			}
			ans[i]=sum;
			// break;
		}
		for(ll i=0;i<n;++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";

	} 
	return 0;
}