#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		vector<ll> a(n,0), b(m,0);
		ll sum=0;
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		for(ll i=0;i<m;++i){
			cin>>b[i];
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		reverse(a.begin(),a.end());
		for(ll i=0;i<n;++i){
			sum+=abs(a[i]-b[m-n+i]);
		}
		for(ll i=0;i<n;++i){
			// i번째를 더하는게 좋은지?
			if(abs(a[i]-b[i])>abs(a[i]-b[m-n+i])){
				sum-=abs(a[i]-b[m-n+i]);
				sum+=abs(a[i]-b[i]);
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}