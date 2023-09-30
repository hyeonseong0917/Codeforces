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
		int plus_num=0, minus_num=0;
		for(int i=0;i<n;++i){
			int a=0;
			cin>>a;
			if(a<0){
				++minus_num;
			}else{
				++plus_num;
			}
		}
		int cur_minus_num=n/2;
		if(cur_minus_num%2==1){
			--cur_minus_num;
		}
		int min_num=122232421;
		int cur_plus_num=n-cur_minus_num;
		while(cur_minus_num>=0){
			min_num=min(min_num,abs(minus_num-cur_minus_num));
			cur_minus_num-=2;
		}
		cout<<min_num<<"\n";
	}
	return 0;
}