#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
using namespace std;


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		vector<int> v(n,0);
		map<int,int> a,b;
		for(int i=0;i<n;++i){
			cin>>v[i];
		}
		for(int i=0;i<m;++i){
			int c=0;
			cin>>c;
			++b[c];
			++a[v[i]];
		}
		int cur_cnt=0;
		map<int,int> tmp=b;
		for(int i=0;i<m;++i){
			if(b[v[i]]){
				++cur_cnt;
				--b[v[i]];
			}
		}
		int ans=0;
		b=tmp;
		if(cur_cnt>=k){
			++ans;
		}
		int L=0, R=m-1;
		while(R<n-1){
			--a[v[L]];
			if(b[v[L]]>a[v[L]]){
				--cur_cnt;
			}
			++L;
			++R;
			++a[v[R]];
			if(a[v[R]]<=b[v[R]]){
				++cur_cnt;
			}
			if(cur_cnt>=k){
				++ans;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}