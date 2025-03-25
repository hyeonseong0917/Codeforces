#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
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
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		// v를 바탕으로 새 수열 b를 만들것임
		// c[i]: 첫 i개의 최대공약수
		// c[0]: b[0]과 b[1]의 최대공약수
		// c[1]: b[0],b[1],b[2]의 최대공약수
		// 수열 c가 사전 순으로 최대
		sort(v.rbegin(),v.rend());
		vector<ll> b;
		b.push_back(v[0]);
		vector<ll> tmp;
		for(ll i=1;i<=sqrt(v[0]);++i){
			if(v[0]%i!=0) continue;
			tmp.push_back(i);
			if(i!=sqrt(v[0])){
				tmp.push_back(v[0]/i);
			}
		}
		sort(tmp.rbegin(),tmp.rend());
		vector<ll> check(n,0);
		ll pre_num=v[0];
		for(ll i=0;i<tmp.size();++i){
			// tmp[i]의 배수 있는지, 있다면
			if(pre_num%tmp[i]!=0) continue;
			for(ll j=1;j<n;++j){
				if(check[j]) continue;
				if(v[j]%tmp[i]==0){
					pre_num=tmp[i];
					++check[j];
					// cout<<i<<" "<<j<<" "<<tmp[i]<<endl;
					b.push_back(v[j]);
				}
			}
		}
		for(ll i=0;i<n;++i){
			cout<<b[i]<<" ";
		}cout<<"\n";

	} 
	return 0;
}