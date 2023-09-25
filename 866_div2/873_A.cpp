#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		bool flag=0;
		int cnt=0;
		if(s=="^"){
			cout<<1<<"\n";
			continue;
		}
		for(int i=0;i<s.size();++i){
			if(s[i]=='^'){
				flag=1;
			}else{
				if(flag){
					if(i+1<s.size() && s[i+1]=='^'){
						continue;
					}
					++cnt;
				}else{
					if(i+1<s.size() && s[i+1]=='^'){
						++cnt;
					}else{
						cnt+=2;	
					}
					
					flag=1;
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}