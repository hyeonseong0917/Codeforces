#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
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
		int n;
		cin>>n;
		vector<int> a(n,0),b(n,0);
		for(int i=0;i<n;++i){
			cin>>a[i];
		}
		for(int i=0;i<n;++i){
			cin>>b[i];
		}
		int ans=0;
		bool flag=0;
		for(int i=0;i<n;++i){
			if(a[i]>b[i]){
				flag=1;
				break;
			}
		}
		if(!flag){
			cout<<0<<"\n";
		}else{
			for(int i=0;i<n;++i){
				vector<int> tmp;
				++ans;
				// i+1개만큼 1을 앞에 넣는다
				for(int j=0;j<=i;++j){
					tmp.push_back(1);
				}
				
				for(int j=0;tmp.size()<n;++j){
					tmp.push_back(a[j]);
				}
				// for(int j=0;j<tmp.size();++j){
				// 	cout<<tmp[j]<<" ";
				// }cout<<endl;
				bool flag=0;
				for(int j=0;j<n;++j){
					if(tmp[j]>b[j]){
						flag=1;
						break;
					}
				}
				if(!flag){
					break;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}