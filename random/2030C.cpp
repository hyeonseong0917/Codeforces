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
		bool is_all_zero=1;
		for(ll i=0;i<s.size();++i){
			if(s[i]=='1'){
				is_all_zero=0;
				break;
			}
		}
		if(n==2 || is_all_zero){
			if(is_all_zero){
				cout<<"NO"<<"\n";
			}else{
				cout<<"YES"<<"\n";
			}
			continue;
		}
		bool flag=0;
		ll turn=0;
		vector<ll> idx;
		for(ll i=0;i<s.size()-1;++i){
			if(s[i]!=s[i+1]){
				if(turn%2==1){
					idx.push_back(i);
				}
				++turn;
			}
		}
		for(ll i=0;i<idx.size();++i){
			s[idx[i]]='0';
			s[idx[i]+1]='0';
		}
		for(ll i=0;i<s.size();++i){
			if(s[i]=='1'){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
		
	} 	

	return 0;
}