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
		ll a1,a2,a3,a4;
		cin>>a1>>a2>>a3>>a4;
		if(a1==0){
			cout<<1<<"\n";
			continue;
		}
		ll sum=a1+a2+a3+a4;
		// A와 B가 있음
		ll A=a1;
		ll B=a1;
		ll ans=A;
		// 1 1 1 1
		// a2는 A만 좋아하고 B는 싫어함
		// a3는 B만 좋아하고 A는 싫어함
		// a4는 A와 B둘다 싫어함
		// 모든 쇼를 끝내거나, 누군가의 점수가 음수가 되면 끝남

		// a2<a3
		if(a2<a3){
			// a2를 다 소모시키기
			A+=a2;
			B-=a2;
			ans+=a2;
			// a3를 최대 A만큼 다 소모시키기
			ll cur_cost=min(A,a3);
			A-=cur_cost;
			B+=cur_cost;
			ans+=cur_cost;
			a3-=cur_cost;
			// a4를 소모시키기
			if(!a4){
				// a4가 0이라면?
				if(a3){
					// cur_cost가 a3보다 크다 = a3를 모두 썼다
					++ans;
				}
			}else{
				// a4가 0이 아니라면?
				// a4를 얼마만큼 써야할까?
				// a4를 cur_a4_cost만큼 쓴다
				ll cur_a4_cost=min(A,min(B,a4));
				ans+=cur_a4_cost;
				a4-=cur_a4_cost;
				if(a4){
					++ans;
				}
			}
		}else{
			// a3<=a2
			// a3를 다 소모시키기
			// 1 1 1 1
			A-=a3;
			B+=a3;
			ans+=a3;
			// a2를 최대 B만큼 다 소모시키기
			ll cur_cost=min(a2,B);
			A+=cur_cost;
			B-=cur_cost;
			ans+=cur_cost;
			a2-=cur_cost;
			if(!a4){
				if(a2){
					++ans;
				}
			}else{
				ll cur_a4_cost=min(A,min(B,a4));
				ans+=cur_a4_cost;
				a4-=cur_a4_cost;
				if(a4){
					++ans;
				}
			}
		}

		cout<<min(ans,sum)<<"\n";
	} 
	return 0;
}