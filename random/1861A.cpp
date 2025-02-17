#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long

ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}

int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		ll num=-1;
		for(ll i=0;i<9;++i){
			for(ll j=i+1;j<9;++j){
				string k="";
				k+=s[i];
				k+=s[j];
				ll k_num=stoll(k);
				bool flag=0;
				for(ll p=2;p<k_num;++p){
					if(k_num%p==0){
						flag=1;
						break;
					}
				}
				if(!flag){
					num=k_num;
				}
			}
		}
		if(num!=-1){
			cout<<num<<"\n";
		}else{
			cout<<-1<<"\n";
		}

	} 	

	return 0;
}