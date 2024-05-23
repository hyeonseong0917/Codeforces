#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
using namespace std;

#define ll long long
map<ll,ll> m;
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> v(n,0);
		bool flag=0;
		for(int i=0;i<n;++i){
			cin>>v[i];
			if(v[0]!=v[i]){
				flag=1;
			}
		}
		if(n==1 || !flag){
			cout<<1<<"\n";
			continue;
		}
		int idx=0;
		int k=1;
		int target=v[0]|v[1];
		while(idx+k<n && k<n){
			int cur_num=0;
			for(int i=idx;i<=idx+k;++i){
				cur_num=cur_num|v[i];
			}
			if(cur_num==target){
				++idx;
			}else{
				--idx;
				++k;
				if(k<n){
					target|=v[k];	
				}
			}
		}
		cout<<k+1<<"\n";
		// while(idx+)
		
	}
	return 0;
}