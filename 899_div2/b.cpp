#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	// your code goes here
	int t=0;
	cin>>t;
	int n=0;
	while(t--){
		
		int y=0;
		int x=0;
		int n=0;
		cin>>n;
		string s;
		cin>>s;
		bool flag=0;
		for(int i=0;i<s.size();++i){
			if(s[i]=='U'){
				y+=1;
			}else if(s[i]=='D'){
				y-=1;
			}else if(s[i]=='R'){
				x+=1;
			}else{
				x-=1;
			}
			// cout<<x<<" "<<y<<"\n";
			if(y==1 && x==1){
				flag=1;
				break;
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