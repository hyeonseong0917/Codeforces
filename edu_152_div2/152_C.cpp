#include <iostream>
using namespace std;

//1717

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		string s="";
		cin>>s;
		bool flag=0;
		for(int i=0;i<s.size();++i){
			if(s[i]=='?'){
				flag=1;
				break;
			}
		}
		if(flag==0){
			cout<<s<<endl;
			continue;
		}
		if(s.size()==1){
			if(s[0]=='?'){
				cout<<"0"<<endl;
			}else{
				cout<<s<<endl;
			}
			continue;
		}
		string ans="";
		if(s[0]=='?'){
			ans+='0';
			s[0]='0';
			
		}else{
			ans+=s[0];
		}
		
		for(int i=1;i<s.size();++i){
			if(s[i]=='?'){
				ans+=s[i-1];
				s[i]=s[i-1];
			}else{
				ans+=s[i];
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}