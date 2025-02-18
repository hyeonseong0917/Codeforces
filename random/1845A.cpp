#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long

ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}

int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		// n을 얻고싶음
		// 1에서 k까지 x만 제외하고 무한히 있음
		// n을 만들 수 있는지?
		ll n,k,x;
		cin>>n>>k>>x;
		if(x!=1){
			cout<<"YES"<<"\n";
			cout<<n<<"\n";
			for(ll i=1;i<=n;++i){
				cout<<1<<" ";
			}cout<<"\n";
		}else{
			// x==1
			// 1에서 k까지
			if(k==1){
				cout<<"NO"<<"\n";
			}else if(k==2){
				if(n%2==0){
					cout<<"YES"<<"\n";
					cout<<n/2<<"\n";
					for(ll i=0;i<n/2;++i){
						cout<<2<<" ";
					}cout<<"\n";
				}else{
					cout<<"NO"<<"\n";
				}
			}else{
				// k>=3
				cout<<"YES"<<"\n";
				if(n%2==0){
					cout<<n/2<<"\n";
					for(ll i=0;i<n/2;++i){
						cout<<2<<" ";
					}cout<<"\n";
				}else{
					cout<<(n-3)/2+1<<"\n";
					cout<<3<<" ";
					for(ll i=0;i<(n-3)/2;++i){
						cout<<2<<" ";
					}cout<<"\n";
				}
			}
		}
	} 	

	return 0;
}