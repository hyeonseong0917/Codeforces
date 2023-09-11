#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		int n=0;
		cin>>n;
		long long maxNum=-1;
		long long minNum=1000000000+5;
		long long secondMinNum=1000000000+5;
		int secondMinIdx=-1;
		long long sum=0;
		vector<long long> v[25000+1];
		for(int i=0;i<n;++i){
			int m=0;
			cin>>m;
			for(int j=0;j<m;++j){
				long long a=0;
				cin>>a;
				minNum=min(minNum,a);
				v[i].push_back(a);
			}
			sort(v[i].begin(),v[i].end());
			if(v[i][1]<secondMinNum){
				secondMinNum=v[i][1];
				secondMinIdx=i;
			}
		}
		for(int i=0;i<n;++i){
			if(i==secondMinIdx){
				sum+=minNum;
			}else{
				sum+=v[i][1];
			}
		}
		cout<<sum<<"\n";
		// cout<<"\n";		
	}
	return 0;
}