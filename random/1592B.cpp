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
		// i와 j를 골라서, |i-j|>=x 인경우에만 v[i]와 v[j] swap
		// v를 비내림차순으로 가능?
		ll n,x;
		cin>>n>>x;
		vector<ll> v(n,0);
		vector<ll> tmp(n,0);
		vector<pair<ll,ll>> p;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			tmp[i]=v[i];
		}
		sort(tmp.begin(),tmp.end());
		bool flag=0;
		if(n<2*x){
			for(ll i=n-x;i<x;++i){
				if(tmp[i]!=v[i]){
					flag=1;
					break;
				}

			}
		}
		if(flag){
			cout<<"NO"<<"\n";
		}else{
			cout<<"YES"<<"\n";
		}
		// 인덱스의 차이값이 x보다 크거나 같은 경우에만 바꾸기가능
		// x=2
		// 0 1 2 3 4
		// 5 1 1 2 3
		// 5 3 1 2 1
		// 1 3 1 2 5
		// 1 3 5 2 1
		// 1 1 5 2 3
		// 2 1 5 1 3
		// 5 1 2 1 3
		// 1 1 2 5 3
		// 5 1 2 1 3
		// 3 1 2 1 5
		// 1 1 2 3 5

		// 1 2 3 4 5
		// x=3 가능함
		// 5 2 3 1 4
		
		// x=3
		// 5 3 4 1 2
		// 1 3 4 5 2
		// 1 2 4 5 3
		
		// n=6, x=5
		// 0 1 2 3 4 5
		// 5 5 1 3 4 2
		// 

		// i번째에 해당하는 수를 끝으로 보내기

		// 0 1 2 3 4
		// 5 4 3 2 1
		// 중간의 수를 끝으로 보내지 못하는데 성공할 수 있나?
		// x<=n
		// 0 1 2 3 4 x=3
		// 5 1 2 3 4
		// 5 4 2 3 1
		// 1 4 2 3 5
		// 1 
	} 
	return 0;
}