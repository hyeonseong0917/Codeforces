#include <iostream>
#include <string>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		string s="";
		cin>>s;
		// if(t==0){
		// 	cout<<s;
		// }
		int N=s.size();
		string s1,s2;
		s1=s.substr(0,N/2);
		if(N%2==0){
			s2=s.substr(N/2);
		}else{
			s2=s.substr((N/2)+1);
		}
		if(s1.compare(s2)==0){
			bool flag=0;
			for(int i=0;i<s1.size()-1;++i){
				if(s1[i]!=s1[i+1]){
					flag=1;
					break;
				}
			}
			if(flag){
				cout<<"YES"<<endl;
			}else{
				cout<<"NO"<<endl;	
			}
			
		}else{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}