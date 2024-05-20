#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n,0),p(n,0);
		for(int i=0;i<n;++i){
			cin>>a[i];
		}
		map<int,int> m;
		int MEX=0;
		for(int i=0;i<n;++i){
			if(a[i]<0){
				p[i]=MEX-a[i];
				++m[p[i]];
			}else{
				p[i]=MEX;
				++MEX;
				while(1){
					if(m[MEX]){
						++MEX;
					}else{
						break;
					}
				}
			}
		}
		for(int i=0;i<n;++i){
			cout<<p[i]<<" ";
		}cout<<"\n";

	} 
	return 0;
}