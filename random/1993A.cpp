#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		string s;
		cin>>s;
		ll a=0, b=0, c=0, d=0;
		for(ll i=0;i<s.size();++i){
			if(s[i]=='?') continue;
			if(s[i]=='A'){
				++a;
			}else if(s[i]=='B'){
				++b;
			}else if(s[i]=='C'){
				++c;
			}else{
				++d;
			}
		}
		a=min(a,n);
		b=min(b,n);
		c=min(c,n);
		d=min(d,n);
		cout<<a+b+c+d<<"\n";
		
	}
	return 0;
}