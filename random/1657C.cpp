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
		ll c=0, r=0;
		// c는 oper 횟수, r은 남은 string의 길이
		ll idx=0;
		while(idx<n-1){
			if(s[idx]=='('){
				idx+=2;
				++c;
			}else{
				// s[idx]==')'
				ll R=idx+1;
				bool flag=0;
				while(R<n){
					if(s[R]==')'){
						flag=1;
						break;
					}
					++R;
				}
				ll tmp=R;
				// cout<<R<<endl;
				if(!flag) break;
				ll L=idx;
				// L과 R사이 대칭인지??
				bool is_same=1;
				while(L<=R){
					if(s[L]==s[R]){
						++L;
						--R;
					}else{
						is_same=0;
						break;
					}
				}
				if(is_same){
					++c;
					idx=tmp+1;
				}else{
					break;
				}
			}
		}
		r=n-idx;
		cout<<c<<" "<<r<<"\n";
	} 
	return 0;
}