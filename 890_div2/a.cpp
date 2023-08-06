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
		for(int i=0;i<n;++i){
			for(int j=i+1;j<n;++j){
				if(v[i]>v[j] && v[i]>0){
					cnt+=v[i];
					int cur_num=v[i];
					for(int k=0;k<n;++k){
						if(v[k]>0){
							// cout<<i<<" "<<v[i]<<endl;
							v[k]=max(0,v[k]-cur_num);
						}	
					}
				}
				// for(int k=0;k<n;++k){
				// 	cout<<v[k]<<" ";
				// }cout<<endl;
			}
		}
		cout<<cnt<<"\n";
		cout<<"\n";
	}
	return 0;
}