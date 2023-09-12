#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int n,m,k;
		int x,y;
		cin>>n>>m>>k;
		cin>>x>>y;

		bool isCapture=0;
		if((x+y)%2==0){
			for(int i=0;i<k;++i){
				int xx,yy;
				cin>>xx>>yy;
				if((xx+yy)%2==0){
					isCapture=1;
				}
			}
			if(isCapture==1){
				cout<<"NO"<<"\n";
			}else{
				cout<<"YES"<<"\n";
			}
		}else{
			for(int i=0;i<k;++i){
				int xx,yy;
				cin>>xx>>yy;
				if((xx+yy)%2==1){
					isCapture=1;
				}
			}
			if(isCapture==1){
				cout<<"NO"<<"\n";
			}else{
				cout<<"YES"<<"\n";
			}
		}
		
	}
	return 0;
}