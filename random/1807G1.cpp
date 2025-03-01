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
		// a는 처음에 1만 가지고 있음
		// a의 subsequence 골라서 a에 subsequence 합 add
		// c가 처음 수로부터 얻어질 수 이쓴지?
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> check(5000+1,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		if(v[0]!=1){
			cout<<"NO"<<"\n";
			continue;
		}
		check[1]=1;
		bool flag=0;
		for(ll i=1;i<n;++i){
			if(!check[v[i]]){
				flag=1;
				break;
			}
			vector<ll> c;
			for(ll j=1;j<=5000;++j){
				if(check[j]){
					if(v[i]+j<=5000){
						c.push_back(v[i]+j);
					}
				}
			}
			for(ll i=0;i<c.size();++i){
				++check[c[i]];
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