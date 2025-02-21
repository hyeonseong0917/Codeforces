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
		string s;
		cin>>s;
		bool is_exist_zero=0;
		for(ll i=0;i<n;++i){
			if(s[i]=='0'){
				is_exist_zero=1;
			}
		}
		if(!is_exist_zero){
			if(n==4){
				cout<<"YES"<<"\n";
			}else{
				cout<<"NO"<<"\n";
			}
			continue;
		}
		ll idx=0;
		for(ll i=0;i<n;++i){
			if(s[i]=='0'){
				idx=i;
				break;
			}
		}
		--idx;
		if(idx*idx==n){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}

	} 	

	return 0;
}