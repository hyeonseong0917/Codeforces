#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

//a>b
ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
ll lcm(ll a, ll b){
	return (a*b)/gcd(a,b);
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
			
		ll x;
		cin>>x;
		if(x==1){
			cout<<1<<"\n";
			cout<<1<<"\n";
			continue;
		}
		ll p=0;
		ll tmp=x;
		while(x>1){
			x/=2;
			++p;
		}
		vector<ll> v(p+1,0);
		x=tmp;
		while(x){
			if(x>=(ll)pow(2,p)){
				x-=(ll)pow(2,p);
				++v[p];
			}
			--p;
		}
		// 0 1 2 3 4
		// 0 1 1 0 0
		// 0 -1 0 1	
		ll n=v.size();
		for(ll i=0;i<n;++i){
			if(v[i]==1){
				ll idx=i;
				for(ll j=idx+1;j<n;++j){
					if(v[j]==1){
						idx=j;
					}else{
						break;
					}
				}
				if(idx==i) continue;
				if(idx==n-1){
					v[i]=-1;
					for(ll j=i+1;j<=idx;++j){
						v[j]=0;
					}
					v.push_back(1);
				}else{
					v[i]=-1;
					for(ll j=i+1;j<=idx;++j){
						v[j]=0;
					}
					v[idx+1]=1;
				}
			}
		}
		cout<<v.size()<<"\n";
		for(ll i=0;i<v.size();++i){
			cout<<v[i]<<" ";
		}cout<<"\n";
		// for(int i=0;i<v.size();++i){
		// 	cout<<v[i]<<" ";
		// }

	}	
	return 0;
}