#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long
ll c[2000+1][2000+1];
int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		string a="", b="";
		char c='z';
		for(ll i=0;i<s.size();++i){
			if(c>s[i]){
				c=s[i];
			}
		}
		a+=c;
		bool flag=0;
		for(ll i=0;i<s.size();++i){
			if(!flag && s[i]==c){
				flag=1;
				continue;
			}
			b+=s[i];
		}
		cout<<a<<" "<<b<<"\n";
	} 
	return 0;
}