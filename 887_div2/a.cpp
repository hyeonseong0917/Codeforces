#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int n=0;
		cin>>n;
		int cnt=0;
		vector<int> v;
		for(int i=0;i<n;++i){
			int a=0;
			cin>>a;
			v.push_back(a);
		}
		bool isSorted=1;
		for(int i=0;i<n-1;++i){
			if(v[i]>v[i+1]){
				isSorted=0;
				break;
			}
		}
		if(!isSorted){
			cout<<0<<"\n";
			continue;
		}
		int minNum=1222232421;
		for(int i=0;i<n-1;++i){
			minNum=min(minNum,v[i+1]-v[i]);
		}
		cout<<(minNum/2)+1<<"\n";
		cout<<"\n";
	}
	return 0;
}