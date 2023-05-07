#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
 
int getNum(int num){
	
	for(int i=2;i*i<=num;++i){
		if(num%i==0){
			return i;
		}
	}
	return num;
}
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int n,m=0;
		cin>>n>>m;
		if(m==1 || n==1){
			cout<<"YES"<<endl;
			continue;
		}
		int a=getNum(n);
		if(a<=m){
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
		}
		
	}
	return 0;
}