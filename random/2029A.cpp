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
		// 양의 정수 k와 집합 s(l에서 r까지의 ㅗ든 정수가)
		// 1. s에서 수 x를 고른다.
		// 2. k개의 x배수가 존재할 것
		// 3. x를 제거
		// 수행할 수 있는 오퍼레이션의 최대 수를 구해라
		ll l,r,k;
		cin>>l>>r>>k;
		// 배수가 적어도 k개 있어야함
		// 선택한 x에 대해
		// 해당x를 삭제함
		// 4 9 1
		// 3 9 2
		// 1. l*k<=r인지? 아니라면 0
		// 2. l에서 c까지.. c=r/k
		if(l*k<=r){
			cout<<r/k-l+1<<"\n";
		}else{
			cout<<0<<"\n";
		}
	} 
	return 0;
}