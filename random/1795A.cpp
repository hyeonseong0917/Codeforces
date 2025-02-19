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
		// 번갈아 나오게 하고싶음
		ll n,m;
		cin>>n>>m;
		string a,b;
		cin>>a;
		cin>>b;
		ll a_idx=-1;
		for(ll i=0;i<n-1;++i){
			if(a[i]==a[i+1]){
				a_idx=i+1;
				break;
			}
		}
		if(a_idx==-1){
			ll b_idx=-1;
			for(ll i=0;i<m-1;++i){
				if(b[i]==b[i+1]){
					b_idx=i+1;
					break;
				}
			}
			if(b_idx==-1){
				cout<<"YES"<<"\n";
			}else{
				string c=b.substr(b_idx);
				reverse(c.begin(),c.end());
				a+=c;
				bool flag=0;
				for(ll i=0;i<a.size()-1;++i){
					if(a[i]==a[i+1]){
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
			string c=a.substr(a_idx);
			reverse(c.begin(),c.end());
			b+=c;
			bool flag=0;
			for(ll i=0;i<b.size()-1;++i){
				if(b[i]==b[i+1]){
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
	} 	

	return 0;
}