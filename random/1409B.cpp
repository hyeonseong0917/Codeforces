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
		ll a,b,x,y,n;
		cin>>a>>b>>x>>y>>n;
		// a>=x && b>=y
		// n번보다 작거나 같은만큼 operation 수행 가능함
		// a나 b중 하나를 골라서 -1
		// a*b의 최솟값을 구한다
		// a먼저 빼고, b빼기
		ll c=n;
		ll fst_diff=min(a-x,c);
		c-=fst_diff;
		ll sed_diff=min(b-y,c);
		ll fst_num=(a-fst_diff)*(b-sed_diff);

		// b먼저 빼고, a빼기
		c=n;
		fst_diff=min(b-y,c);
		c-=fst_diff;
		sed_diff=min(a-x,c);
		ll sed_num=(b-fst_diff)*(a-sed_diff);
		cout<<min(fst_num,sed_num)<<"\n";

	} 	

	return 0;
}