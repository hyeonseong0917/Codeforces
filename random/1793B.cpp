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
		// 0946
		// a: n개의 정수들이 원에
		// 절댓값의 차는 1임
		// 지역 맥시멈: 이웃한 두 숫자보다 크거나 같다면
		// 지역 미니멈: 이웃한 두 숫자보다 작거나 같다면

		// 지역 맥시멈의 합 x와 지역 미니멈의 합 y는 기억함
		// x와 y를 주어졌을 때 매칭되는 가장최소 길이의 수열을
		ll x,y;
		cin>>x>>y;
		// 2 -1
		// 1 0 -1 0 1 0
		// 지역맥시멈: 1+1
		// 지역미니멈: 

		// 3 -2
		vector<ll> ans;
		ans.push_back(x);
		ll tmp=x;
		while(1){
			if(tmp==y){
				break;
			}
			--tmp;
			ans.push_back(tmp);
		}
		while(1){
			if(tmp==x-1){
				break;
			}
			++tmp;
			ans.push_back(tmp);
		}
		ll as=ans.size();
		cout<<as<<"\n";
		for(ll i=0;i<as;++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";
	} 

	return 0;
}