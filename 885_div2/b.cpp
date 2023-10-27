#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


const int MAX=200000+1;
vector<int> c;

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		int n=0,k=0;
		cin>>n>>k;
		vector<int> last(k+1,-1);
		vector<int> fst_max(k+1,0);
		vector<int> sed_max(k+1,0);
		c.clear();
		for(int i=0;i<k;++i){
			last[i]=-1;
			fst_max[i]=0;
			sed_max[i]=0;
		}
		
		for(int i=0;i<n;++i){
			int a=0;
			cin>>a;
			c.push_back(a);
		}
		for(int i=0;i<n;++i){
			if(fst_max[c[i]]<i-last[c[i]]-1){
				sed_max[c[i]]=fst_max[c[i]];
				fst_max[c[i]]=i-last[c[i]]-1;
			}else if(sed_max[c[i]]<i-last[c[i]]-1){
				sed_max[c[i]]=i-last[c[i]]-1;
			}
			last[c[i]]=i;
		}

		for(int i=1;i<=k;++i){
			if(fst_max[i]<n-last[i]-1){
				sed_max[i]=fst_max[i];
				fst_max[i]=n-last[i]-1;

			}else if(sed_max[i]<n-last[i]-1){
				sed_max[i]=n-last[i]-1;
			}
		}
		int ans=1222232421;
		for(int i=1;i<=k;++i){
			if(last[i]==-1) continue;
			int cur_num=max(fst_max[i]/2,sed_max[i]);
			// cout<<i<<" "<<fst_max[i]<<" "<<sed_max[i]<<endl;
			ans=min(ans,cur_num);
		}
		cout<<ans<<"\n";
		// cout<<min_num_color<<" "<<min_max_num;		
	}
	return 0;
}