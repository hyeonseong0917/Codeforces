#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
int main() {
	// your code goes here 1301
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	ll mod=1000000007;
	while(t--){
		ll n,k;
		cin>>n>>k;
		vector<ll> a(n,0);
		vector<ll> dp(n,-1222232421);
		ll sum=0;
		ll max_num=0;
		for(ll i=0;i<n;++i){
			cin>>a[i];
			sum+=a[i];
		}
		dp[0]=a[0];
		max_num=max(a[0],(ll)0);
		for(ll i=1;i<n;++i){
			dp[i]=max(a[i],dp[i-1]+a[i]);
			if(max_num<dp[i]){
				max_num=dp[i];
			}
		}
		// cout<<max_num<<endl;
		for(ll i=0;i<k;++i){
			sum=(sum+max_num+mod)%mod;
			max_num=(max_num+max_num)%mod;	
		}
		sum=max((ll)0, sum);
		cout<<sum<<"\n";
		

	}
	return 0;
}