#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	vector<int> a,b;
	while(t--){
		int n=0;
		cin>>n;
		int idx=-1;
		int max_quality=-1;
		for(int i=0;i<n;++i){
			int x,y;
			cin>>x>>y;
			if(x<=10){
				if(max_quality<y){
					max_quality=y;
					idx=i+1;
				}
			}
		}
		cout<<idx<<"\n";
		
	}
	return 0;
}