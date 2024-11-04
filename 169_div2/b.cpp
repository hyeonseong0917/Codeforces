#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o;
	cin>>o;
	while(o--){
		ll l,r;
		ll L,R;
		cin>>l>>r;
		cin>>L>>R;
		vector<ll> check(100+1,0);
		for(ll i=l;i<=r;++i){
			++check[i];
		}
		for(ll i=L;i<=R;++i){
			++check[i];
		}
		ll cnt=0;
		for(ll i=1;i<=100;++i){
			if(check[i]>=2){
				++cnt;
			}
		}
		if(cnt==0){
			cnt=1;
		}else{
			cnt+=1;
			if(L==l){
				--cnt;
			}
			if(R==r){
				--cnt;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}