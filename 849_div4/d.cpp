#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long

const int MAX=200000+5;
ll dp[MAX];

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	vector<ll> a;
	ll n,q;
	ll l,r,k;
	ll cur_sum=0;
	while(t--){
		n=0;
		q=0;
		a.clear();
		for(int i=0;i<MAX;++i){
			dp[i]=0;
		}
		cin>>n>>q;
		for(int i=0;i<n;++i){
			ll c=0;
			cin>>c;
			a.push_back(c);
		}
		dp[0]=a[0];
		for(int i=1;i<n;++i){
			dp[i]=dp[i-1]+a[i];
		}
		for(int j=0;j<q;++j){
			l=0;
			r=0;
			k=0;
			cin>>l>>r>>k;
			--r;
			--l;
			cur_sum=0;
			if(l-1>=0){
				cur_sum+=dp[l-1];
			}
			cur_sum+=dp[n-1]-dp[r];
			cur_sum+=(r-l+1)*k;
			if(cur_sum%2==0){
				cout<<"NO"<<"\n";
			}else{
				cout<<"YES"<<"\n";
			}
		}
		
	}
	return 0;
}