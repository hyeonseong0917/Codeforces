#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		ll n=s.size();
		if(n==1){
			cout<<s<<"\n";
			continue;
		}
		for(ll i=0;i<n;++i){
			ll max_num=0;
			ll max_idx=-1;
			for(ll j=i+1;j<=min(n-1,i+9);++j){
				ll c=s[j]-'0';
				if(max_num<c-j+i){
					max_num=c-j+i;
					max_idx=j;
				}
			}
			ll c=s[i]-'0';
			if(max_num>c){
				char tmp=s[i];
				char k=max_num+'0';
				s[i]=k;
				for(ll j=i+1;j<=max_idx;++j){
					char ttmp=s[j];
					s[j]=tmp;
					tmp=ttmp;
				}
			}
		}
		cout<<s<<"\n";
	} 
	return 0;
}