#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		int ans;
		if(b%3==1){
			c-=2;
		}else if(b%3==2){
			// b%3==2
			c-=1;
		}
		if(c<0){
			cout<<-1<<"\n";
		}else{
			ans=a+(b+2)/3+(c+2)/3;
			cout<<ans<<"\n";
		}
		
	}
	
	return 0;
}