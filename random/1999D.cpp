#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int o=1;
	cin>>o;
	while(o--){
		// 313
		// string s가 주어짐 ?가 있음
		// 각 ?를 소문자로 바꾸도록. 서브시퀀스가 되도록
		// t가 s의 서브시퀀스가 되도록
		string s,t;
		cin>>s;
		cin>>t;
		// x->b->x

		// ba??e
		ll idx=0;
		bool flag=0;
		for(ll i=0;i<s.size();++i){
			if(idx==t.size()){
				flag=1;
				break;
			}
			if(s[i]==t[idx] || s[i]=='?'){
				if(s[i]=='?'){
					s[i]=t[idx];
				}
				++idx;
			}
		}
		if(idx==t.size()){
			flag=1;
		}
		if(!flag){
			cout<<"NO"<<"\n";
		}else{
			cout<<"YES"<<"\n";
			for(ll i=0;i<s.size();++i){
				if(s[i]=='?'){
					s[i]='a';
				}
			}
			cout<<s<<"\n";
		}
		// abcde
	} 
	return 0;
}