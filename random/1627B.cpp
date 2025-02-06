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
		// n*m
		// Tina k개의 핑크 페인트 통
		// 1. Tina는 정확히 k개의 자리를 고른다
		// 2. Rahul은 앉을 자리를 정한다 핑크색 제외하고
		// 3. Rahul이 선택한 자리 빼고 아무 자리나 앉는다
		// Rahum은 가능한 한 가깝게, Tina는 가능한 한 멀게
		// k=0에서 n*m-1까지, R과 T가 가능한 한 가깝게 앉는 거리
		ll n,m;
		cin>>n>>m;
		// 4 *3

		//  0 1 2 3
		//0 . . . .
		//1 . . . .
		//2 . . . .
		//3 . . . .

		//  0 1 2 3 4 5
		//0 . . . . . .
		//1 . . . . . .
		//2 . . . . . .
		//3 . . . . . .
		//4 . . . . . .
		//5 . . . . . .

		// R입장에서 어디를 앉아야 좋을까?
		// (1,1),(2,1) => 꼭짓점까지의 최대 거리 3
		// 꼭짓점 까지의 거리 (0,0),(0,2),(3,0),(3,2)
		// 1. y,x를 찾는다(모든 꼭짓점까지의 최댓값이)

		// 결론: 각 꼭짓점까지의 최대 거리를 작은 순으로 나열
		vector<ll> v;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				ll c=0;
				// 0,0에서 i,j
				c=max(c,i+j);

				// 0,m-1에서 i,j
				c=max(c,i+abs(m-1-j));

				// n-1,0에서 i,j
				c=max(c,j+abs(n-1-i));

				// n-1,m-1에서 i,j
				c=max(c,abs(n-1-i)+abs(m-1-j));

				v.push_back(c);
			}
		}
		sort(v.begin(),v.end());
		for(ll i=0;i<v.size();++i){
			cout<<v[i]<<" ";
		}cout<<"\n";
	} 

	return 0;
}