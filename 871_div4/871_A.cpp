#include <iostream>
using namespace std;

//1013
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	string target="codeforces";
	while(t--){
		string s="";
		cin>>s;
		int cnt=0;
		for(int i=0;i<s.size();++i){
			if(s[i]!=target[i]){
				++cnt;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}