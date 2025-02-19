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
		// n+1명의 참가자
		// 나와 n명의 다른 사람들
		// 각 참가자들은 서로 한 번씩
		// i>j인경우에만 i가 이김
		// i번째 사람이 나랑 할 때는 좀 다름
		// i상대로 이기기 위해서는 a[i]분 이상을 준비해야함
		// m분이 주어짐 준비할 수 있는
		ll n,m;
		cin>>n>>m;
		vector<ll> v(n,0);
		vector<ll> w(n,0);
		vector<pair<ll,ll>> p;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			p.push_back({v[i],i});
			v[i]=i;
		}
		sort(p.begin(),p.end());
		// 3 105
		// 0   1   2 3 4 
		// 100 300 3 3 300
		// 0   1   2 3 4

		// 3 102
		// 100 300 1 1 1 1 1 1
		// 0   1   2 3 4 5 6 7

		// i번째 이후후
		
	} 	

	return 0;
}