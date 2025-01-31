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
		// 모든 돌이 1번과 n번에 갈 수 있는지?
		// 최소횟수로
		// 1번의 operation으로 i<j<k골라서 
		// j는 2이상이어야함.
		// j-1과 j+1에 하나씩 전파
		// 1 2 2 3 6
		// 2 0 2 3 7
		// 2 0 2 4 7
		// 왼쪽 끝과 오른쪽 끝을 그냥 냅두고
		// 최소 횟수가 필요
		// 1. 저 사이 숫자를 모두 짝수로 만들어야함
		// 2 2 3 이구간을
		// 홀수를 짝수로 바꾸기 위해 i는 0, j는 아무 짝수, k는 홀수
		// 짝수 제거를 위해서는 v[i]/2만큼의 oper 필요
		// v[1]부터 보면서 짝수로 만들어야함
		// v[1]에서 v[n-2]까지 짝수의 합/2가
		// 홀수 개수보다 작다면 fail
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		ll sum=0;
		ll odd_cnt=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		if(n==3){
			if(v[1]%2==0){
				cout<<v[1]/2<<"\n";
			}else{
				cout<<-1<<"\n";
			}
			continue;
		}
		for(ll i=1;i<n-1;++i){
			sum+=v[i];
			if(v[i]%2==1){
				++odd_cnt;
			}
		}
		if(sum-odd_cnt<=1){
			cout<<-1<<"\n";
		}else{
			cout<<odd_cnt+(sum-odd_cnt)/2<<"\n";
		}
		
		

	} 
	return 0;
}