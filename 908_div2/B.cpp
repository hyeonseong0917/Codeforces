#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ll t=0;
	cin>>t;
	while(t--){
		int N;
		cin>>N;
		vector<int> a(N+1,0);
		for(int i=0;i<N;++i){
			cin>>a[i];
		}
		vector<int> v[100+1];
		vector<int> b(N+1,0);
		for(int i=0;i<N+1;++i){
			v[i].clear();
		}
		map<int,int> multi_check;
		map<int,int> m;
		multi_check.clear();
		m.clear();
		int cnt=0;
		for(int i=0;i<N;++i){
			v[a[i]].push_back(i);
			if(v[a[i]].size()>=2 && !multi_check[a[i]]){
				multi_check[a[i]]=1;
				++cnt;
			}
		}
		bool flag=0;
		if(cnt<=1){
			cout<<-1<<"\n";
		}else{
			// cout<<cnt<<"\n";
			for(int i=0;i<N;++i){
				if(m[a[i]]) continue;
				++m[a[i]];
				if(v[a[i]].size()==1){
					b[i]=1;
				}else{
					if(!flag){
						flag=1;
						b[v[a[i]][0]]=2;
						// cout<<"he"<<v[a[i]][0]<<"\n";
					}else{
						// cout<<"the"<<v[a[i]][0]<<"\n";
						b[v[a[i]][0]]=3;
					}
					for(int j=1;j<v[a[i]].size();++j){
						int cur_idx=v[a[i]][j];
						// cout<<cur_idx<<"\n";
						b[cur_idx]=1;
					}
				}
			}
			for(int i=0;i<N;++i){
				cout<<b[i]<<" ";
			}cout<<"\n";
		}
		
	}
	return 0;
}