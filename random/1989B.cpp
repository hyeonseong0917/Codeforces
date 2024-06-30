#include <iostream>
#include <vector>
#include <map>
#include <stack>
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
		string a="",b="";
		cin>>a>>b;
		int as=a.size();
		int bs=b.size();
		int ans=as+bs;
		for(int i=0;i<bs;++i){
			int cur_idx=i;
			for(int j=0;j<as;++j){
				if(cur_idx==bs) break;
				if(b[cur_idx]==a[j]){
					++cur_idx;
				}
			}
			ans=min(ans,as+bs-(cur_idx-i));
			
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}