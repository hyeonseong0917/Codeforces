#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n,x,y;
		cin>>n>>x>>y;
		// n: 갈아야 한느 과일 수
		// x: 1초에 갈 수 있는 과일 수
		// y: 1초에 넣을 수 있는 과일 수
		ll z=min(x,y);
		cout<<(n+z-1)/z<<"\n";
	} 
	return 0;
}