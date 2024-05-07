#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
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
		string s;
		cin>>s;
		
		ll n=s.size();
		ll idx=n-1;
		ll sum=0;
		ll min_one_idx=-1;
		for(ll i=0;i<n;++i){
			if(s[i]=='1'){
				min_one_idx=i;
				break;
			}
		}
		if(min_one_idx!=-1){

			for(ll i=min_one_idx;i<n;++i){
				if(s[i]=='0'){
					sum+=(i-min_one_idx+1);
					++min_one_idx;
				}
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}