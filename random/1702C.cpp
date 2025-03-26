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
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n+1,1);
		map<ll,ll> min_check,max_check;
		for(ll i=1;i<=n;++i){
			cin>>v[i];
			if(!min_check[v[i]]){
				min_check[v[i]]=i;
			}
			max_check[v[i]]=i;
		}
		
		for(ll i=0;i<k;++i){
			ll a,b;
			cin>>a>>b;
			// a에 해당하는 최초의 인덱스 뒤에
			// 값 b가 존재하는지?
			// a가 나타나는 가장 작은 인덱스
			// b가 나타나는 가장 큰 인덱스
			if(!min_check[a] || !max_check[b]){
				cout<<"NO"<<"\n";
			}else{
				if(min_check[a]>max_check[b]){
					cout<<"NO"<<"\n";
				}else{
					cout<<"YES"<<"\n";
				}
			}
		}

	} 
	return 0;
}