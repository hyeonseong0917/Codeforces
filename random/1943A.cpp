#include <iostream>
#include <vector>
#include <map>
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
		int N;
		cin>>N;
		int max_num=0;
		map<int,int> v;
		for(int i=0;i<N;++i){
			int a=0;
			cin>>a;
			++v[a];
			max_num=max(a,max_num);
		}
		int fst_num=-1;
		for(int i=0;i<=max_num;++i){
			if(v[i]==0) break;
			if(v[i]==1){
				fst_num=i;
				break;
			}
		}	
		int ans=-1;
		if(fst_num==-1){
			for(int i=0;i<=max_num;++i){
				if(v[i]){
					ans=i+1;
				}else{
					ans=i;
					break;
				}
			}
		}else{
			for(int i=fst_num+1;i<=max_num;++i){
				if(v[i]>=2){
					ans=i+1;
				}else{
					break;
				}
			}
			ans=max(ans,fst_num+1);
		}
		cout<<ans<<"\n";

	}
	
	return 0;
}