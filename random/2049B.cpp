#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		string s;
		cin>>s;
		if(s[0]=='s'){
			s[0]='.';
		}
		if(s[n-1]=='p'){
			s[n-1]='.';
		}
		ll p_cnt=0, s_cnt=0;
		for(ll i=0;i<n;++i){
			if(s[i]=='s') ++s_cnt;
			if(s[i]=='p') ++p_cnt;
		}
		if(p_cnt==0 || s_cnt==0){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}

	}
	return 0;
}