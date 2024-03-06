#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int N;
		cin>>N;
		vector<int> v;
		map<int,int> m;
		int max_num=0;
		for(int i=0;i<N;++i){
			int a=0;
			cin>>a;
			max_num=max(max_num,a);
			v.push_back(a);
			++m[a];
		}
		int cur_num=-1;
		for(int i=0;i<=N;++i){
			if(!m[i]){
				cur_num=i;
				break;
			}
		}
		
		int cnt=0;
		map<int,int> tmp_map;
		int idx=-1;
		for(int i=0;i<N-1;++i){
			if(v[i]<cur_num){
				--m[v[i]];
				if(!tmp_map[v[i]]){
					++tmp_map[v[i]];
					++cnt;
				}
			}
			if(cnt==cur_num){
				idx=i;
				break;
			}
		}
		// cout<<cur_num<<"\n";
		if(cur_num!=cnt){
			cout<<-1<<"\n";
			continue;
		}
		bool flag=0;
		for(int i=0;i<cur_num;++i){
			if(!m[i]){
				flag=1;
				break;
			}
		}
		if(flag || idx==-1){
			cout<<-1<<"\n";
		}else{
			cout<<2<<"\n";
			cout<<1<<" "<<idx+1<<"\n";
			cout<<idx+2<<" "<<N<<"\n";
			
		}
		
	}
	return 0;
}