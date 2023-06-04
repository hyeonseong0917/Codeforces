#include <iostream>
#include <cmath>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int n,k=0;
		int res=0;
		cin>>n>>k;
		double c=(double)(n-1)/k;
		double d=ceil(c);
		res+=d;
		res+=1;
		cout<<res<<"\n";
	}
	return 0;
}