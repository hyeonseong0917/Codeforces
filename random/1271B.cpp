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
		ll n;
		cin>>n;
		string s;
		cin>>s;
		if(n==2){
			if(s[0]==s[1]){
				cout<<0;
			}else{
				cout<<-1;
			}
			continue;
		}
		// i번째를 W로 만들기? i는 n-2까지 보면서
		vector<ll> ans;
		string tmp=s;
		for(ll i=0;i<n-1;++i){
			if(tmp[i]=='B'){
				tmp[i]='W';
				if(tmp[i+1]=='B'){
					tmp[i+1]='W';
				}else{
					tmp[i+1]='B';
				}
				ans.push_back(i+1);
			}
		}
		if(tmp[n-1]=='W'){
			ll as=ans.size();
			cout<<as<<"\n";
			for(ll i=0;i<as;++i){
				cout<<ans[i]<<" ";
			}
			continue;
		}
		ans.clear();
		tmp=s;
		for(ll i=0;i<n-1;++i){
			if(tmp[i]=='W'){
				tmp[i]='B';
				if(tmp[i+1]=='W'){
					tmp[i+1]='B';
				}else{
					tmp[i+1]='W';
				}
				ans.push_back(i+1);
			}
		}
		if(tmp[n-1]=='B'){
			ll as=ans.size();
			cout<<as<<"\n";
			for(ll i=0;i<as;++i){
				cout<<ans[i]<<" ";
			}
			continue;
		}
		cout<<-1;
	} 	

	return 0;
}