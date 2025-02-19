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
		// a는 ugly이다. 만약 i버쨰 원소가 이전 원소의 합과 같다면
		// 비내림차순 a가 주어짐짐
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		if(n==2){
			if(v[0]==v[1]){
				cout<<"NO"<<"\n";
			}else{
				cout<<"YES"<<"\n";
				cout<<v[0]<<" "<<v[1]<<"\n";
			}
			continue;
		}
		// n>=3
		// 0 1 2 3
		// 3 3 6 6
		// 4 1 4 4
		reverse(v.begin(),v.end());
		if(v[n-1]==v[0]){
			cout<<"NO"<<"\n";
		}else{
			cout<<"YES"<<"\n";
			cout<<v[n-1]<<" ";
			for(ll i=0;i<n-1;++i){
				cout<<v[i]<<" ";
			}cout<<"\n";
		}
		
	} 	

	return 0;
}