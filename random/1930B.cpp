#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int n=0;
		cin>>n;
		vector<int> ans;
		for(int i=1;i<=(n+1)/2;++i){
			ans.push_back(i);
			if(i!=n+1-i){
				ans.push_back(n+1-i);	
			}
		}
		for(int i=0;i<n;++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";
	}
	return 0;
}