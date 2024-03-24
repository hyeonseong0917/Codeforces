#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#define ll long long
using namespace std;

ll GCD(ll a, ll b)
{
	if (b == 0) {
		return a;
	}
	else {
		return GCD(b, a % b);
	}
}
ll LCM(ll a, ll b) 
{
	return a * b / GCD(a, b);
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	
	while(t--){
		int n=0;
		cin>>n;
		vector<ll> a(200000+1,0);
		vector<ll> ans(200000+1,0);
		for(int i=0;i<n;++i){
			ll x=0;
			cin>>x;
			if(x<=200000){
				++a[x];
			}
		}
		// sort(a.begin(),a.end());
		ll maxIdx=-1;
		ll maxNum=-1;
		for(int i=1;i<=n;++i){
			for(int j=i;j<=n;j+=i){
				ans[j]+=a[i];
			}
		}
		for(int i=1;i<=n;++i){
			if(ans[i]>maxNum){
				maxNum=ans[i];
				maxIdx=i;
			}
		}
		cout<<maxNum<<"\n";
		// cout<<"\n";
	}
	return 0;
}