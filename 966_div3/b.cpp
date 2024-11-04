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
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		if(n==1){
			cout<<"YES"<<"\n";
			continue;
		}
		vector<ll> check(n+1,0);
		bool flag=1;
		check[v[0]]=1;
		for(ll i=1;i<n;++i){
			if(v[i]==1 || v[i]==n){
				if(v[i]==1){
					if(check[2]){
						check[v[i]]=1;
					}else{
						flag=0;
						break;
					}
				}else{
					if(check[n-1]){
						check[n-1]=1;
					}else{
						flag=0;
						break;
					}
				}
			}else{
				if(check[v[i]-1] || check[v[i]+1]){
					++check[v[i]];
				}else{
					flag=0;
					break;
				}
			}
		}
		if(!flag){
			cout<<"NO"<<"\n";
		}else{
			cout<<"YES"<<"\n";
		}
	}
	return 0;
}