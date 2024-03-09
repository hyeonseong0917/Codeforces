#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
using namespace std;

bool comp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
	if(a.second.second==b.second.second){
		return a.second.first<b.second.first;
	}
	return a.second.second<b.second.second;
}
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		int n,Q;
		cin>>n;
		vector<int> v;
		map<int,int> is_same;
		int cnt=0;
		for(int i=0;i<n;++i){
			int a=0;
			cin>>a;
			if(!is_same[a]){
				++is_same[a];
				++cnt;
			}
			v.push_back(a);
		}
		cin>>Q;
		vector<pair<int,pair<int,int>>> q;
		for(int i=0;i<Q;++i){
			int a,b;
			cin>>a>>b;
			q.push_back({i,{a-1,b-1}});
		}
		if(cnt==1){
			for(int i=0;i<Q;++i){
				cout<<-1<<" "<<-1<<"\n";
			}cout<<"\n";
			continue;
		}
		sort(q.begin(),q.end(),comp);
		map<int,pair<int,int>> ans;
		map<int,int> m;
		for(int i=0;i<Q;++i){
			int cur_idx=q[i].first;
			int start_idx=q[i].second.first;
			int final_idx=q[i].second.second;
			if(v[start_idx]!=v[final_idx]){
				ans[cur_idx]={start_idx,final_idx};
				m[v[start_idx]]=final_idx;
			}else{
				if(m[v[start_idx]]){
					if(start_idx<m[v[start_idx]] && m[v[start_idx]]<final_idx){
						// if(start_idx==1 && final_idx==3){
						// 	cout<<"he"<<" "<<m[v[start_idx]]<<" "<<"\n";
						// }
						ans[cur_idx]={start_idx,m[v[start_idx]]};
					}else{
						int L=start_idx;
						int R=final_idx;
						while(L<R){
							if(v[L]!=v[R]){
								m[v[start_idx]]=R;
								break;
							}
							--R;
						}
						if(L==R){
							ans[cur_idx]={-1,-1};
						}else{
							ans[cur_idx]={start_idx,R};
						}
					}
				}else{
					int L=start_idx;
					int R=final_idx;
					while(L<R){
						if(v[L]!=v[R]){
							m[v[start_idx]]=R;
							break;
						}
						--R;
					}
					if(L==R){
						ans[cur_idx]={-1,-1};
						
					}else{
						ans[cur_idx]={start_idx,R};
					}
				}
			}
		}
		for(int i=0;i<Q;++i){
			if(ans[i].first!=-1 && ans[i].second!=-1){
				cout<<ans[i].first+1<<" "<<ans[i].second+1<<"\n";
			}else{
				cout<<ans[i].first<<" "<<ans[i].second<<"\n";	
			}
			
		}cout<<"\n";
	}
	return 0;
}