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
		int n,k;
		cin>>n>>k;
		vector<int> v;
		for(int i=0;i<n;++i){
			int a=0;
			cin>>a;
			v.push_back(a);
		}
		int cur_num=v[k-1];
		int fst_big_idx=-1;
		int ans=0;
		for(int i=0;i<k;++i){
			if(v[i]>cur_num){
				fst_big_idx=i;
				break;
			}
		}
		if(fst_big_idx==-1){
			int tmp=v[0];
			v[0]=v[k-1];
			v[k-1]=tmp;
			for(int i=1;i<n;++i){
				if(v[i]<cur_num){
					++ans;
				}else{
					break;
				}
			}
		}else{
			int tmp=v[0];
			v[0]=v[k-1];
			v[k-1]=tmp;
			for(int i=1;i<n;++i){
				if(v[i]<cur_num){
					++ans;
				}else{
					break;
				}
			}
			tmp=v[0];
			v[0]=v[k-1];
			v[k-1]=tmp;
			//bid_idx로 바꾸었을 때?
			tmp=v[fst_big_idx];
			v[fst_big_idx]=v[k-1];
			v[k-1]=tmp;
			int cur_cnt=0;
			if(fst_big_idx!=0){
				++cur_cnt;
			}
			for(int i=fst_big_idx+1;i<n;++i){
				if(v[i]<cur_num){
					++cur_cnt;
				}else{
					break;
				}
			}
			ans=max(ans,cur_cnt);
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}