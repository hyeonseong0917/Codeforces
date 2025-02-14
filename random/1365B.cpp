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
		ll n;
		cin>>n;
		vector<ll> a(n,0), b(n,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		bool is_all_zero=1, is_all_one=1;
		for(ll i=0;i<n;++i){
			cin>>b[i];
			if(b[i]==1){
				is_all_zero=0;
			}else{
				is_all_one=0;
			}
		}
		if(is_all_zero || is_all_one){
			bool flag=0;
			for(ll i=0;i<n-1;++i){
				if(a[i]>a[i+1]){
					flag=1;
					break;
				}
			}
			if(flag){
				cout<<"No"<<"\n";
			}else{
				cout<<"Yes"<<"\n";
			}
		}else{
			cout<<"Yes"<<"\n";
		}
	} 	

	return 0;
}