#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		char c;
		cin>>c;
		string s="codeforces";
		bool flag=0;
		for(int i=0;i<s.size();++i){
			if(s[i]==c){
				cout<<"YES"<<"\n";
				flag=1;
				break;
			}
		}
		if(flag==0){
			cout<<"NO"<<"\n";
		}
		
	}
	return 0;
}