#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
using namespace std;

#define ll long long

ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n,x;
		cin>>n>>x;
		ll sum=0;
		vector<ll> v;
		for(ll i=0;i<n;++i){
			ll a,b,c;
			cin>>a>>b>>c;
			v.push_back(a*b-c);
			sum+=a*(b-1);
		}
		sort(v.rbegin(),v.rend());
		ll max_step=v[0];
		if(max_step<=0){
			if(sum>=x){
				cout<<0<<"\n";
			}else{
				cout<<-1<<"\n";
			}
		}else{
			// 롤백을 r번 했음
			// r*max_step+sum>=x를 만족해야함
			// x-sum>=0??
			if(sum>=x){
				cout<<0<<"\n";
				continue;
			}
			// r*max_step>=x-sum
			// r>=(x-sum)/max_step
			ll r=((x-sum)+max_step-1)/max_step;
			cout<<r<<"\n";
		}
	} 
	return 0;
}