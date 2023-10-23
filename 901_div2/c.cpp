	#include <iostream>
	#include <vector>
	#include <set>
	#include <map>
	#include <algorithm>

	using namespace std;

	#define ll long long

	const int MAX=1000+1;


	ll gcd(ll a, ll b){
		if(b==0){
			return a;
		}else{
			return gcd(b,a%b);
		}

	}
	int main() {
		// your code goes here
		ios_base :: sync_with_stdio(false); 
		cin.tie(NULL); 
		cout.tie(NULL);
		int t=0;
		cin>>t;
		map<ll,ll> mm;
		ll cur_num=1;
		while(1){
			if(cur_num>1000000000){
				break;
			}
			mm[cur_num]=1;
			cur_num*=2;
		}
		// cout<<m[1024];
		while(t--){
			ll n,m;
			cin>>n>>m;
			n=n%m;
			if(n==0 || m==1){
				cout<<0<<"\n";
				continue;
			}
			if(m%2==1 || !mm[m/gcd(m,n)]){
				cout<<-1<<"\n";
				continue;
			}
			ll ans=0;
			while(n){
				ans+=n;
				n*=2;
				if(n>=m){
					n-=m;
				}
			}
			cout<<ans<<"\n";
		}	
		return 0;
	}