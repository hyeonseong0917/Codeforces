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
	cin>>t;
	while(t--){
		ll n,m,k;
		cin>>n>>m>>k;
		if(max(n,m)<k){
			cout<<-1<<"\n";
		}else{
			string ans="";
			if(n>=m){
				// 0이 더 많음
				for(ll i=0;i<k;++i){
					ans+='0';
				}
				n-=k;
				if(n>m){
					cout<<-1<<"\n";
					continue;
				}else{
					for(ll i=0;i<m;++i){
						ans+='1';
						if(n){
							--n;
							ans+='0';
						}
					}
				}
			}else{
				// 1이 더 많음
				for(ll i=0;i<k;++i){
					ans+='1';
				}
				m-=k;
				if(m>n){
					cout<<-1<<"\n";
					continue;
				}else{
					// n>=m
					for(ll i=0;i<n;++i){
						ans+='0';
						if(m){
							--m;
							ans+='1';
						}
					}
				}
			}
			cout<<ans<<"\n";
		}
	} 	

	return 0;
}