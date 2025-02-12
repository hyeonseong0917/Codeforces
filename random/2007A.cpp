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
		// set s
		// [L,R]의 모든 정수를 ㅓㅎ음
		// a,b,c의 서로 다른 정수를 고른다. 서로소가 1인
		// 행할 수 있는 최대의 operation 수는?
		// 3개의 수는 홀수여야할까?
		// 짝홀홀도 가능
		// 2씩 차이나는 홀홀홀 가능
		// [11,13,15]
		// [17,19,0]
		ll L,R;
		cin>>L>>R;
		ll ans=0;
		while(L<=R-2){
			if(L%2==1 && (L+1)%2==0 && (L+2)%2==1){
				++ans;
				L+=3;
			}else{
				++L;
			}
		}
		
		
		cout<<ans<<"\n";
	} 	

	return 0;
}