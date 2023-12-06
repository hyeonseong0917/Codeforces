#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int a,b,c;
		vector<int> v;
		cin>>a>>b>>c;

		// 1에 대해
		if((b+c)%2==0){
			v.push_back(1);
		}else{
			v.push_back(0);
		}
		//2에 대해
		if((a+c)%2==0){
			v.push_back(1);
		}else{
			v.push_back(0);
		}
		//3
		if((a+b)%2==0){
			v.push_back(1);
		}else{
			v.push_back(0);
		}
		for(int i=0;i<3;++i){
			cout<<v[i]<<" ";
		}cout<<"\n";
	}
	return 0;
}