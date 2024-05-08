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
		vector<int> v(n,0);
		for(int i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		if(v[0]!=1){
			cout<<"Alice"<<"\n";
		}else{
			int seg_len=1;
			int cur_idx=-1;
			for(int i=0;i<n;++i){
				if(v[i]==seg_len) continue;
				if(v[i]==seg_len+1){
					++seg_len;
				}else{
					cur_idx=i;
					break;
				}
			}
			if(seg_len%2==0){
				if(cur_idx==-1){
					cout<<"Bob"<<"\n";
				}else{
					cout<<"Alice"<<"\n";
				}
			}else{
				if(cur_idx==-1){
					cout<<"Alice"<<"\n";
				}else{
					cout<<"Bob"<<"\n";
				}
			}
		}
	}
	
	return 0;
}