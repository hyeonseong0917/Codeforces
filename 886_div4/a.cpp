#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		bool flag=0;
		if(a+b>=10 || a+c>=10 || b+c>=10){
			flag=1;
		}
		if(flag){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
		
	}
	return 0;
}