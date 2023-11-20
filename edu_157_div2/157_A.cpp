#include <iostream>
#include <vector>
using namespace std;

//1555
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int x,y,k;
		cin>>x>>y>>k;
		if(x>=y){
			cout<<x<<"\n";
		}else{
			if(x+k>=y){
				cout<<y<<"\n";
			}else{
				cout<<y+y-(x+k)<<"\n";
			}
		}		
	}
	return 0;
}