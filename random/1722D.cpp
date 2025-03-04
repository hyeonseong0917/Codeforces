#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		// 1057
		ll n;
		// LRRLL
		// 03234
		// 41231 (만약 바꾼다면)
		// +4, -2, 0, 0, -3: 처음꺼 - 바꾼거
		// 1에서 n까지 각 k에 대해
		// 최대 k명의 방향을 변경할 수 있을 때 점수의 최댓값
		// 점수: 모든 점수의 합
		// 누구를 바꾸는게 좋을까?
		// 만약 바꾼다면의 값들 중 증가폭이 큰 순대로
		cin>>n;
		string s;
		cin>>s;
		vector<ll> ans;
		vector<ll> diff;
		ll sum=0;
		for(ll i=0;i<s.size();++i){
			if(s[i]=='L'){
				sum+=i;
				diff.push_back((i-(n-i-1))*-1);
			}else{
				sum+=n-i-1;
				diff.push_back((n-i-1-i)*-1);
			}
		}
		sort(diff.rbegin(),diff.rend());
		for(ll i=0;i<n;++i){
			// cout<<diff[i]<<endl;
			if(diff[i]<=0){
				ans.push_back(sum);
				continue;
			}
			sum+=diff[i];
			ans.push_back(sum);
		}
		for(ll i=0;i<n;++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";

	} 
	return 0;
}