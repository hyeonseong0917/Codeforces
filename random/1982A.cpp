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
		ll x1,y1,x2,y2;
		cin>>x1>>y1;
		cin>>x2>>y2;
		// 동점이 불가능한 경우가 하나라도 있으면 YES
		// 무조건 동점이 발생하면 NO
		if(x1<y1){
			if(x2>=y2){
				cout<<"NO"<<"\n";
			}else{
				cout<<"YES"<<"\n";
			}
		}else{
			if(x2<=y2){
				cout<<"NO"<<"\n";
			}else{
				cout<<"YES"<<"\n";
			}
		}
	} 
	return 0;
}