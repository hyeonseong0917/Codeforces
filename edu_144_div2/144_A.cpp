#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	string target="FBFFBFFBFBFFBFFBFBFFB";
	while(t--){
		int k=0;
		string s="";
		cin>>k;
		cin>>s;
		bool flag=0;
		for(int i=0;i<target.size();++i){
			for(int j=1;i+j<=target.size();++j){
				string cur_str=target.substr(i,j);
				if(cur_str==s){
					flag=1;
				}
			}
		}
		if(flag){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
	}
	return 0;
}