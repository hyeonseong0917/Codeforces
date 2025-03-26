#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long
vector<ll> sieve(ll n) {
    vector<bool> is_prime(n + 1, true);
    vector<ll> primes;
    
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    
    for (ll i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    
    return primes;
}

int main() {
	// your code goes here
	int o=1;
	cin>>o;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> tmp = sieve(n);
		sort(tmp.begin(),tmp.end());
		// for(ll i=0;i<tmp.size();++i){
		// 	cout<<tmp[i]<<" ";
		// }cout<<"\n";
		ll ans=0;
		ll ts=tmp.size();
		for(ll i=1;i<n;++i){
			// i*v[idx]가 n보다 작은 최대의 idx구하기
			ll L=0, R=ts-1;
			ll idx=-1;
			while(L<=R){
				ll mid=(L+R)/2;
				if(i*tmp[mid]<=n){
					idx=max(idx,mid);
					L=mid+1;
				}else{
					R=mid-1;
				}
			}
			ans+=idx+1;
		}
		cout<<ans<<"\n";
	} 

	return 0;
}