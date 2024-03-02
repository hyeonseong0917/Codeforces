#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

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
		ll a,b,n;
		cin>>a>>b>>n;
		vector<ll> v;
		for(int i=0;i<n;++i){
			ll k=0;
			cin>>k;
			v.push_back(k);
		}	
		sort(v.begin(),v.end());
		ll cur_time=0;
		int idx=0;
		while(1){
			if(idx==n){
				cur_time+=1;
				break;
			}
			if(b==1 && idx<n){
				b+=v[idx];
				b=min(a,b);
				++idx;
			}
			cur_time+=(b-1);
			b=1;
		}
		cout<<cur_time<<"\n";

		
	}	
	return 0;
}