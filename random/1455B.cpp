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
		// 0이 점에 서있다. x>0으로 이동하고 싶음
		// 나는 현재 y에 있다. k번 이동하고 싶음
		// k번째 점프에 대해서,
		// y+k로 이동하거나, y-1로 이동함
		// x로 이동하기 위한 최소 점프 횟수
		ll x;
		cin>>x;	
		// x보다 처음으로 크거나 같아질 때까지 1+2+..+n
		// 초과한 만큼 뒤로 가면?
		ll ans=0;
		ll minus_cnt=0;
		for(ll i=1;i<=x;++i){
			// 1에서 i까지 더한 경우
			ll sum=((i+1)*i)/2;
			if(sum>=x){
				minus_cnt=sum-x;
				ans+=i+sum-x;
				break;
			}
		}
		if(minus_cnt>1){
			ans-=minus_cnt;
		}
		cout<<ans<<"\n";
	} 

	return 0;
}