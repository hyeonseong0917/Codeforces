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
		ll n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		if(k%2==0){
			sort(s.begin(),s.end());
			cout<<s<<"\n";
		}else{
			vector<char> odd_v, even_v;
			for(ll i=0;i<n;++i){
				if(i%2==0){
					even_v.push_back(s[i]);
				}else{
					odd_v.push_back(s[i]);
				}
			}
			sort(odd_v.begin(),odd_v.end());
			sort(even_v.begin(),even_v.end());
			ll os=odd_v.size();
			ll es=even_v.size();
			string ans="";
			for(ll i=0;i<max(os,es);++i){
				if(i<es){
					ans+=even_v[i];
				}
				if(i<os){
					ans+=odd_v[i];
				}
			}
			cout<<ans<<"\n";
		}

	} 	

	return 0;
}