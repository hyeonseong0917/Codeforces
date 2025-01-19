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
		ll n;
		cin>>n;
		string s;
		cin>>s;
		ll fst_num, last_num;
		if(s[0]=='1'){
			fst_num=2;
			last_num=2;
			cout<<1;
		}else{
			fst_num=1;
			last_num=1;
			cout<<1;
		}
		if(n==2){
			cout<<"\n";
			continue;
		}
		cout<<" ";
		for(ll x=3;x<=n;++x){
			if(s[x-2]=='0'){
				cout<<last_num<<" ";
				fst_num=1;
			}else{
				cout<<x-fst_num<<" ";
				fst_num+=1;
				last_num=x;
			}
		}
		cout<<"\n";
		
	} 
	return 0;
}