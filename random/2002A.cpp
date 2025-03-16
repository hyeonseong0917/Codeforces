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
		ll n,m,k;
		cin>>n>>m>>k;
		// 같은 색의 셀 간 거리가 k보다 크거나 같아야함
		// 1 4
		// 2 3
		// 3 2
		// 4 1
		cout<<min(n,k)*min(m,k)<<"\n";
	} 

	return 0;
}