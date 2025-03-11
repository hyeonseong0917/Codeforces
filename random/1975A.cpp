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
		// a를 비내림차순으로 정렬할 수 이쓴지?
		// 1. a를 두 부분으로 분할
		// 2. 순서를 바꿔서 이어붙일 수 있음
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		bool flag=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			if(i!=0){
				if(v[i-1]>v[i]){
					flag=1;
				}
			}
		}
		if(!flag){
			cout<<"YES"<<"\n";
		}else{
			flag=0;
			for(ll i=1;i<=n-1;++i){
				vector<ll> tmp;
				for(ll j=0;j<i;++j){
					tmp.push_back(v[j]);
				}
				vector<ll> tv;
				for(ll j=i;j<n;++j){
					tv.push_back(v[j]);
				}
				for(ll j=0;j<tmp.size();++j){
					tv.push_back(tmp[j]);
				}
				bool c=0;
				for(ll j=1;j<n;++j){
					if(tv[j-1]>tv[j]){
						c=1;
						break;
					}
				}
				// cout<<i<<" "<<c<<endl;
				if(!c){
					flag=1;
					break;
				}
			}
			if(flag){
				cout<<"YES"<<"\n";
			}else{
				cout<<"NO"<<"\n";
			}
		}

	} 
	return 0;
}