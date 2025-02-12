#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		// S={n}
		// S에서 u를 선택하고 하나를 지운다.
		// k개이하의 정수를 S에 넣는다 모든 삽입된 정수의 합이
		// u가 되도록
		// S가 n개의 1을 가지도록 최소의 operation
		ll n,k;
		cin>>n>>k;
		// k-1개의 1을 쓰는 것?
		// 16
		// 1 1 1 13 ans=1
		// 1 1 1 1 1 1 10 ans=2
		// 1 1 1 1 1 1 1 1 8
		ll ans=0;
		while(n>1){
			n-=(k-1);
			++ans;
		}
		cout<<ans<<"\n";


		

	} 	

	return 0;
}