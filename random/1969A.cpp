#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> v(n+1);
		for(int i=1;i<=n;++i){
			cin>>v[i];
		}
		bool flag=0;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if(v[i]==j && v[j]==i){
					flag=1;
					break;
				}
			}
		}
		int ans=(flag)?2:3;
		cout<<ans<<"\n";

	} 
	return 0;
}