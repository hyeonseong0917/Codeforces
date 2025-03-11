#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int o=1;
	cin>>o;
	while(o--){
		// 자물쇠에는 정수 x 표시
		// 1. 두개의 연속된 3제거(33아니면)
		// 2. x>=33이면 x-33가능
		// x를 0으로 만들 수 있는지?
		ll x;
		cin>>x;
		if(x<33){
			cout<<"NO"<<"\n";
		}else{
			// x>=33
			if(x%33==0){
				cout<<"YES"<<"\n";
			}else{
				// 3333
				cout<<"NO"<<"\n";
			}
		}
	} 
	return 0;
}