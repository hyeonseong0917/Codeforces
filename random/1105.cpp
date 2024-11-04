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
	ll t=1;
	while(t--){
		ll L,R;
		cin>>L>>R;
		string left_string=to_string(L);
		string right_string=to_string(R);
		ll cnt=0;
		ll ls=left_string.size();
		for(ll i=0;i<ls;++i){
			if(left_string[i]=='8'){
				++cnt;
			}
		}
		if(cnt==0){
			cout<<cnt;
			break;
		}
		for(ll i=ls-1;i>=0;--i){
			if(left_string[i]=='8'){
				left_string[i]='9';
				for(ll j=i+1;j<ls;++j){
					left_string[j]='0';
				}
				ll cur_num=stoll(left_string);
				// cout<<cur_num<<endl;
				if(cur_num>R){
					break;
				}
				--cnt;
			}
		}
		cout<<cnt;

	}
	return 0;
}