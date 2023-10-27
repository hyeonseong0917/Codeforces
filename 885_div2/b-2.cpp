#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
 

vector<int> c;
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
		c.clear();
		
		
		vector<pair<int,int>> pq[k+1];
        vector<int> max_dist[k+1];
        for(int i=0;i<k+1;++i){
			pq[i].clear();
			max_dist[i].clear();
		}
		for(int i=0;i<n;++i){
			int a=0;
			cin>>a;
			c.push_back(a);
		}
		//{거리,idx}
 
		for(int i=0;i<n;++i){
 
			if(pq[c[i]].empty()){
				max_dist[c[i]].push_back(i);
				pq[c[i]].push_back({i,i});
			}else{
				int last_idx=pq[c[i]].size()-1;
				int cur_dist=i-pq[c[i]][last_idx].second-1;
				pq[c[i]].push_back({cur_dist,i});
 
				if(max_dist[c[i]].empty()){
 
					max_dist[c[i]].push_back(cur_dist);
				}else{
					if(max_dist[c[i]].size()==1){
						max_dist[c[i]].push_back(cur_dist);	
					}else if(max_dist[c[i]].size()==2){
						sort(max_dist[c[i]].begin(), max_dist[c[i]].end());
						max_dist[c[i]][0]=max(max_dist[c[i]][0],cur_dist);
					}
				}
			}
		}
 
		for(int i=1;i<=k;++i){
			if(pq[i].empty()) continue;
			int ps=pq[i].size();
			int cur_dist=n-pq[i][ps-1].second-1;
			// cout<<i<<" "<<cur_dist<<"\n";
			pq[i].push_back({n-pq[i][ps-1].second-1,n});	
			if(max_dist[i].empty()){
				max_dist[i].push_back(cur_dist);
			}else{
				if(max_dist[i].size()==1){
					max_dist[i].push_back(cur_dist);	
					sort(max_dist[i].begin(), max_dist[i].end());
				}else if(max_dist[i].size()==2){
					sort(max_dist[i].begin(), max_dist[i].end());
					max_dist[i][0]=max(max_dist[i][0],cur_dist);
					sort(max_dist[i].begin(), max_dist[i].end());
				}
			}
		}
 
		// 색깔 별 첫번째, 두번째로 최대 길이만 알면 됨
		int min_num_color=-1;
		int min_max_num=1222232421;
		for(int i=1;i<=k;++i){
			if(pq[i].empty()) continue;
			int ps=pq[i].size();
			int cur_max_dist;
			if(ps>1){
				cur_max_dist=max(max_dist[i][1]/2, max_dist[i][0]);
			}else{
				cur_max_dist=max_dist[i][0]/2;
			}
			// cout<<i<<" "<<cur_max_dist<<"\n";
			min_max_num=min(min_max_num,cur_max_dist);
		}
		cout<<min_max_num<<"\n";
		
		
		// cout<<min_num_color<<" "<<min_max_num;		
	}
	return 0;
}