#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int n=0;
		cin>>n;
		int maxNum=1222232421;
		for(int i=0;i<n;++i){
			int d,s;
			cin>>d>>s;
			maxNum=min(maxNum,d+((s+1)/2)-1);
		}
		cout<<maxNum<<endl;
		cout<<endl;
	}
	return 0;
}