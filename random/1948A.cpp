#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int a=0;
		cin>>a;
		if(a==1 || (a-3)%4==0 || (a-1)%4==0){
			cout<<"NO"<<"\n";
		}else{
			// a>=3
			string ans="";
			for(int i=0;i<a/4;++i){
				ans+="AABB";
			}
			if(a%4==1){
				ans+='A';
			}else if(a%4==2){
				ans+="AA";
			}else if(a%4==3){
				ans+="AAB";
			}
			cout<<"YES"<<"\n";
			cout<<ans<<"\n";
		}
	}
	
	return 0;
}