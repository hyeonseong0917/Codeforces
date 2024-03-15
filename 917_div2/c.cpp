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
		int N,K,D;
		cin>>N>>K>>D;
		vector<int> a,v;
		for(int i=0;i<N;++i){
			int c=0;
			cin>>c;
			a.push_back(c);
		}
		for(int i=0;i<K;++i){
			int c=0;
			cin>>c;
			v.push_back(c);
		}
		int ans=0;
		for(int i=0;i<min(2*N,D);++i){
			int cnt=0;
			for(int j=0;j<N;++j){
				if(a[j]==j+1) ++cnt;
			}
			ans=max(ans,cnt+(D-(i+1))/2);
			for(int j=0;j<v[i%K];++j){
				++a[j];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}