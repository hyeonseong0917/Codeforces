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
		string s="";
		for(ll i=0;i<50;++i){
			s+="Yes";
		}
		string k;
		cin>>k;
		ll ks=k.size();
		bool flag=0;
		for(ll i=0;i<150-ks;++i){
			string tmp=s.substr(i,ks);
			if(tmp.compare(k)==0){
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