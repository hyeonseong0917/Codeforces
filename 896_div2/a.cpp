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
		vector<int> v;
		bool isAllZero=1;
		int cnt=0;
		for(int i=0;i<n;++i){
			int a=0;
			cin>>a;
			if(a!=0){
				isAllZero=0;
			}
			v.push_back(a);
		}
		if(isAllZero){
			cout<<0<<"\n";
		}else{
			if(n%2==0){
				cout<<2<<"\n";
				cout<<1<<" "<<n<<"\n";
				cout<<1<<" "<<n<<"\n";
			}else{
				cout<<4<<"\n";
				cout<<1<<" "<<n-1<<"\n";
				cout<<1<<" "<<n-1<<"\n";
				cout<<n-1<<" "<<n<<"\n";
				cout<<n-1<<" "<<n<<"\n";
			}
		}
		
	}
	return 0;
}