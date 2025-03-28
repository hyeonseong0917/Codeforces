#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	int t=1;
	// cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		// 1에서 n까지의 정수와 또다른 정수 k
		// 1<=k<=n
		// l[i]<=r[i]
		vector<ll> v(n,0);
		vector<ll> tmp;
		ll sum=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			if(v[i]>n-k){
				sum+=v[i];
				tmp.push_back(i);
			}
		}
		ll mod=998244353;
		// v를 k개의 구간으로 나눈다
		// 각 구간의 최댓값을 더한 값의 최댓값
		
		// sum인 구간의 개수?
		ll cnt=1;
		vector<ll> diff;
		for(ll i=1;i<tmp.size();++i){
			diff.push_back(tmp[i]-tmp[i-1]-1);
		}
		for(ll i=0;i<diff.size();++i){
			cnt*=diff[i]+1;
			cnt%=mod;
		}
		cout<<sum<<" "<<cnt;

	} 	

	return 0;
}