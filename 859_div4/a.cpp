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
		if(a+b==c){
			cout<<"+"<<"\n";
		}else{
			cout<<"-"<<"\n";
		}
		
	}
	return 0;
}