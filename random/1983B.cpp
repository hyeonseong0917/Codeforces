#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define ll long long

bool comp(pair<ll,ll> a, pair<ll,ll> b){
	return a.first>b.first;
}

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		string aa[n+1],bb[n+1];
		for(ll i=0;i<n;++i){
			cin>>aa[i];
		}
		for(ll i=0;i<n;++i){
			cin>>bb[i];
		}
		ll a[n+1][m+1], b[n+1][m+1];
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				ll cur_a=aa[i][j]-'0';
				a[i][j]=cur_a;
				ll cur_b=bb[i][j]-'0';
				b[i][j]=cur_b;
			}
		}
		// for(ll i=0;i<n;++i){
		// 	for(ll j=0;j<m;++j){
		// 		cout<<a[i][j];
		// 	}cout<<"\n";
		// }
		// for(ll i=0;i<n;++i){
		// 	for(ll j=0;j<m;++j){
		// 		cout<<b[i][j];
		// 	}cout<<"\n";
		// }
		for(ll i=0;i<n-1;++i){
			for(ll j=0;j<m-1;++j){
				if(a[i][j]!=b[i][j]){
					ll a_num=a[i][j];
					ll b_num=b[i][j];
					// 0,1,2
					ll fst_diff=(b_num-a_num+3)%3;
					ll sed_diff=3-fst_diff;
					a[i][j]+=fst_diff;
					a[i][j]%=3;
					a[i+1][j+1]+=fst_diff;
					a[i+1][j+1]%=3;
					a[i+1][j]+=sed_diff;
					a[i+1][j]%=3;
					a[i][j+1]+=sed_diff;
					a[i][j+1]%=3;
					
				}
			}
		}
		bool is_same=1;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				// cout<<a[i][j]<<" ";
				if(a[i][j]!=b[i][j]){
					is_same=0;
					break;
				}
			}
			// cout<<endl;
		}
		if(is_same){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
	} 
	return 0;
}