#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		string arr[8];
		for(int i=0;i<8;++i){
			cin>>arr[i];
		}
		int y=-1,x=-1;
		for(int i=0;i<8;++i){
			for(int j=0;j<8;++j){
				if(arr[i][j]!='.'){
					y=i;
					x=j;
					break;
				}
			}
			if(x!=-1){
				break;
			}
		}
		for(int i=y;i<8;++i){
			if(arr[i][x]!='.'){
				cout<<arr[i][x];
			}else{
				
				break;
			}
		}	
		cout<<"\n";
		cout<<"\n";
		
	}
	return 0;
}