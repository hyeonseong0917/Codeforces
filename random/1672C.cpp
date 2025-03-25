#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
 
#define ll long long
ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
ll lcm(ll a, ll b){
	return (a*b)/gcd(a,b);
}

int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		// 길이 n의 수열 a
		// 동등성 -> a[i]=a[i+1]의 개수
		// i와 x를 골라서 a[i]와 a[i+1]에 x를 대입
		// 최소의 operation 수 -> 1보다 작거나 같은 수의
		// 동등성을 만족하느 수열로 만들기 위해
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		
		// 0 1 2 3 4 5 6
		// 1 1 2 3 3 3 4
		// 1 5 5 3 3 3 4
		// 1 5 6 6 3 3 4
		// 1 5 6 7 7 3 4

		// 1 1 2 3 3 4

		// 처음으로 연속 시작하는 인덱스부터
		// 마지막으로 연속 인덱스까지?
		ll start_idx=-1, fin_idx=-1;
		for(ll i=1;i<n;++i){
			if(v[i]==v[i-1]){
				start_idx=i;
				break;
			}
		}
		for(ll i=n-2;i>=0;--i){
			if(v[i]==v[i+1]){
				fin_idx=i;
				break;
			}
		}
		if(start_idx==-1 || fin_idx==-1 || start_idx>fin_idx){
			cout<<0<<"\n";
			continue;
		}
		// 2 3 1 1 3 2
		if(start_idx==fin_idx){
			cout<<1<<"\n";
			continue;
		}
		cout<<abs(start_idx-fin_idx)<<"\n";
	} 
	return 0;
}