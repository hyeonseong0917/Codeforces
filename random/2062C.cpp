#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		ll sum=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			sum+=v[i];
		}
		// n<=50
		// |a[i]|<=1000
		// 1번의 operation 수행하면
		// [a1,a2,a3,a4...]
		// [a2-a1,a3-a2,a4-a3...]
		// a의 max_sum을 구한다
		while(1){
			ll vs=v.size();
			if(vs==1) break;
			ll diff=0;
			for(ll i=1;i<vs;++i){
				diff+=v[i]-v[i-1];
			}
			if(diff<0){
				reverse(v.begin(),v.end());
				diff*=-1;
			}
			sum=max(sum,diff);
			vector<ll> tmp;
			for(ll i=1;i<vs;++i){
				tmp.push_back(v[i]-v[i-1]);
			}
			v.clear();
			for(ll i=0;i<tmp.size();++i){
				v.push_back(tmp[i]);
			}
		}
		cout<<sum<<"\n";


	}
	return 0;
}