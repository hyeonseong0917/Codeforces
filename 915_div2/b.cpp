#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long

vector<int> g[100000+1];
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		int n;
		for(int i=0;i<100000+1;++i){
			g[i].clear();
		}
		cin>>n;
		for(int i=0;i<n-1;++i){
			int a,b;
			cin>>a>>b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(g[i].size()==1){
				++cnt;
			}
		}
		cout<<(cnt-1)/2+1<<"\n";
	}	
	return 0;
}