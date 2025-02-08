#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	int t=1;
	cin>>t;
	// 1053
	while(t--){
		string s;
		cin>>s;
		reverse(s.begin(),s.end());
		for(ll i=0;i<s.size();++i){
			if(s[i]=='p'){
				s[i]='q';
			}else if(s[i]=='q'){
				s[i]='p';
			}
		}
		cout<<s<<"\n";
	} 	

	return 0;
}