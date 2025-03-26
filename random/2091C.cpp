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
		// circular lock을 풀어야 한다
		// 이 코드는 매일 업데이트됨
		// 오늘의 코드는 1에서 n까지의 순열
		// 사이클릭 시프트
		// 이 순열을 어떤 방향으로든 한칸씩 이동 시켰을 때
		// 정확히 하나의 고정된 숫자 존재
		// arr[i]=i가 성립하는 하나의 순열
		ll n;
		cin>>n;
		if(n%2==0){
			cout<<-1<<"\n";
			continue;
		}
		vector<ll> v(n+1,0);
		v[n/2+1]=n/2+1;
		ll c=1;
		for(ll i=n;i>n/2+1;--i){
			v[i]=c++;
		}
		c=n;
		for(ll i=1;i<n/2+1;++i){
			v[i]=c--;
		}
		for(ll i=1;i<=n;++i){
			cout<<v[i]<<" ";
		}cout<<"\n";
	} 

	return 0;
}