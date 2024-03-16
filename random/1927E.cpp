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
		int n,k;
		cin>>n>>k;
		vector<int> v(n,0);
		// v.push_back(1);
		int min_num=1;
		int max_num=n;
		for(int i=1;i<=k;++i){
			for(int j=0;i+j*k<=n;++j){
				if(i%2==1){
					v[i+j*k-1]=min_num++;	
				}else{
					v[i+j*k-1]=max_num--;
				}
			}
		}
		for(int i=0;i<n;++i){
			cout<<v[i]<<" ";
		}cout<<"\n";
	}
	return 0;
}