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
		ll n,k;
		cin>>n>>k;
		vector<ll> l(n,0), r(n,0);
		for(ll i=0;i<n;++i){
			cin>>l[i];
		}
		for(ll i=0;i<n;++i){
			cin>>r[i];
		}
		// x개의 글러브를 뽑아도 최소 k개의 서로 다른 매칭 글러브가 생기도록 하는
		// x의 최솟값
		ll ans=400000000000000+1;
		// k개의 매칭 글러브를 생기도록
		// n개에 대해서 둘 중 큰거 다 더함 일단
		// 작은거 중 큰 순으로 k개
		ll sum=0;
		for(ll i=0;i<n;++i){
			sum+=max(l[i],r[i]);
		}
		vector<ll> v;
		for(ll i=0;i<n;++i){
			if(l[i]<=r[i]){
				v.push_back(l[i]);
			}else{
				v.push_back(r[i]);
			}
		}
		sort(v.rbegin(),v.rend());
		for(ll i=0;i<k-1;++i){
			sum+=v[i];
		}
		++sum;
		cout<<sum<<"\n";
	} 
	return 0;
}