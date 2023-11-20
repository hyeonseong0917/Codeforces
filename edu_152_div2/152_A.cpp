#include <iostream>
#include <vector>
using namespace std;

//1555
#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int b,c,h;
		cin>>b>>c>>h;
		if(c+h+1>=b){
			cout<<b*2-1<<"\n";
		}else{
			cout<<(c+h)*2+1<<"\n";
		}
		
	}
	return 0;
}