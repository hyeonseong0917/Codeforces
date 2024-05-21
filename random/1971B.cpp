#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		bool flag=0;
		for(int i=0;i<s.size();++i){
			if(s[i]!=s[0]){
				flag=1;
				break;
			}
		}
		if(!flag){
			cout<<"NO"<<"\n";
		}else{
			cout<<"YES"<<"\n";
			string ans="";
			for(int i=0;i<s.size();++i){
				string cur_str=s.substr(0,i+1);
				string next_str=s.substr(i+1,s.size()-1-(i+1)+1);
				string new_str=next_str+cur_str;
				if(new_str.compare(s)!=0){
					ans=new_str;
					break;
				}
			}
			cout<<ans<<"\n";
		}
	} 
	return 0;
}