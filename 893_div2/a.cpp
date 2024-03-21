#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		if(c%2==1){
			--b;
		}
		if(a<=b){
			cout<<"Second"<<"\n";
		}else{
			cout<<"First"<<"\n";
		}
	}
	return 0;
}