#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long
ll mod=998244353;
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		// 정ㅇ수 n 을 주었다(n>=3)
        // 증가하는 수열. n개의 원소를 가지는 만들기 가능?
        // 3*a[i+2]가 a[i]+a[i+1]로 나누어지지 않아야
        ll n;
        cin>>n;
        // 1 3 5 7 9 11 13 15
        vector<ll> v;
        v.push_back(1);
        for(ll i=1;i<n;++i){
            v.push_back(v[i-1]+2);
        }
        for(ll i=0;i<n;++i){
            cout<<v[i]<<" ";
        }cout<<"\n";
	} 
	return 0;
}