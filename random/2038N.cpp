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
		string s;
		cin>>s;
		if(s[1]=='='){
			if(s[0]==s[2]){
				cout<<s<<"\n";
			}else if(s[0]<s[2]){
				s[1]='<';
				cout<<s<<"\n";
			}else{
				s[1]='>';
				cout<<s<<"\n";
			}
		}else if(s[1]=='<'){
			if(s[0]==s[2]){
				s[1]='=';
			}else if(s[0]>s[2]){
				s[1]='>';
			}
			cout<<s<<"\n";
		}else{
			if(s[0]==s[2]){
				s[1]='=';
			}else if(s[0]<s[2]){
				s[1]='<';
			}
			cout<<s<<"\n";
		}

	} 
	return 0;
}