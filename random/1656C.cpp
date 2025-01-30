#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		bool is_same=1;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			if(v[i]!=v[0]){
				is_same=0;
			}
		}
		if(is_same){
			cout<<"YES"<<"\n";
		}else{
			// 1이 있어도 다 같은 수가 될 수 있음
			sort(v.rbegin(),v.rend());
			// 8 7 4 1 0
			// 8 6 5 2
			// 0 0 
			// 1이 아닌 홀수라면 v[i]-2로 나누면 됨
			// 짝수라면 그냥 2로 나누기
			// 만약 1이 있다면 다 1로 맞추기
			bool is_exist_one=0;
			for(ll i=0;i<n;++i){
				if(v[i]==1){
					is_exist_one=1;
				}
			}
			if(is_exist_one){
				// 다 1로 만들어야함
				// 9 8 7 1
				// 9 6 3 1
				// 8 7
				// 0이나 2가 있으면
				bool flag=0;
				for(ll i=0;i<n;++i){
					if(v[i]==0 || v[i]==2){
						flag=1;
						break;
					}
				}
				if(flag){
					cout<<"NO"<<"\n";
				}else{
					for(ll i=0;i<n-1;++i){
						if(v[i]==v[i+1]+1){
							flag=1;
							break;
						}
					}
					if(flag){
						cout<<"NO"<<"\n";
					}else{
						cout<<"YES"<<"\n";
					}
					
				}
			}else{
				// 1이 없다면 무조건 가능한가??
				cout<<"YES"<<"\n";
			}
		}

	} 
	return 0;
}