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
		// 1045
		// Alice는 a개의 코인 가짐
		// profitable 열려면 최소 b코인이 필요함
		// unprofitable -> coin 아무개나 ㄱㅊ
		// x에 un열었으면,  profit 여는데 필요한 코인 2x줄어듦
		// Alice의 최대 코인, 그녀가 pro를 열 수 있는.
		// 만약 그녀가 처으메 unprofitable에 투자했을 때
		// 못열면 0
		ll a,b;
		cin>>a>>b;
		if(a>=b){
			cout<<a<<"\n";
		}else{
			// a<b
			// 7 9
			// -x -2x
			// 6 7
			// 5 5
			// a-x>=b-2x
			// x>=b-a
			ll x=b-a;
			a-=x;
			b-=2*x;
			if(a<0 || b<0){
				cout<<0<<"\n";
			}else{
				cout<<b<<"\n";
			}
		}
	} 	

	return 0;
}