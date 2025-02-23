#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long
ll mod=998244353;
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		// operation 몇 번 적용가능
        // 2<=x<=n에서 몇 x를 고름
        // 새로운 순열을 만듦
        // p의 모든 원소들을 씀 x보다 작은. 순서 안바꾸고
        // x보다 크거나 같은 원소들 다 씀

        // p[i]=i를 만들기 위해 필요한 최소의 operation
        ll n;
        cin>>n;
        vector<ll> v(n,0);
        for(ll i=0;i<n;++i){
            cin>>v[i];
        }
        vector<ll> dp(n+2,0);
        ll ans=0;
        vector<ll> check(n+2,0);
        // for(ll i=1;i<=n;++i){
        //     dp[i]=1;
        // }
        dp[v[0]]=1;
        for(ll i=1;i<n;++i){
            dp[v[i]]=dp[v[i]+1]+1;
        }
        for(ll i=n-1;i>=0;--i){
            if(check[v[i]]){
                ++check[v[i]+1];
            }else{
                ans+=dp[v[i]]-1;
                ++check[v[i]];
                ++check[v[i]+1];
            }
        }
        cout<<ans<<"\n";
        // for(ll i=1;i<=n;++i){
        //     cout<<i<<" "<<dp[i]<<"\n";
        // }
	} 
	return 0;
}