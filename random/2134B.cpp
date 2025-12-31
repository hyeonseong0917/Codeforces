#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long
ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}

int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		if(k%2==1){
			for(ll i=0;i<n;++i){
				if(v[i]%2!=0){
					v[i]+=k;
				}
			}
		}else{
			// k가 짝수인경우
			if(k==2){
				for(ll i=0;i<n;++i){
					if(v[i]%3==1){
						v[i]+=k;
					}else if(v[i]%3==2){
						v[i]+=k*2;
					}
				}
			}else{
				// k-1을 공통의 배수로
				ll c=k-1;
				for(ll i=0;i<n;++i){
					if(v[i]%c==0) continue;
					ll cnt=c-((v[i]+k-1)%(k-1));
					// cout<<cnt<<endl;
					v[i]+=k*cnt;
				}
			}
		}
		for(ll i=0;i<n;++i){
			cout<<v[i]<<" ";
		}cout<<"\n";
		
	} 	

	return 0;
}