#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int N=0;
		cin>>N;
		char c;
		cin>>c;
		vector<int> v[26+1];
		int t_cnt=0;
		for(int i=0;i<2*N;++i){
			string s;
			cin>>s;
			if(s[1]==c){
				++t_cnt;
			}
			v[s[1]-'A'].push_back(s[0]-'0');
		}

		int total_cnt=0;
		for(int i=0;i<26;++i){
			if(v[i].size()){
				sort(v[i].begin(), v[i].end());
				int cur_num=c-'A';
				if(cur_num==i) continue;
				if(v[i].size()%2!=0){
					++total_cnt;
				}
			}
		}
		if(total_cnt>t_cnt){
			cout<<"IMPOSSIBLE"<<"\n";
		}else{
			int idx=0;
			for(int i=0;i<26;++i){
				if(v[i].size()){
					int cur_num=c-'A';
					if(cur_num==i) continue;
					if(v[i].size()%2==0){
						int v_idx=0;
						while(v_idx<v[i].size()-1){
							char fst_char='A'+i;
							cout<<v[i][v_idx++]<<fst_char<<" "<<v[i][v_idx++]<<fst_char<<"\n";
						}
					}else{
						int v_idx=0;
						char fst_char='A'+i;
						// cout<<"he"<<" "<<i<<" "<<v[i].size()<<"\n";
						cout<<v[i][v_idx++]<<fst_char<<" "<<v[c-'A'][idx++]<<c<<"\n";
						while(v_idx<v[i].size()-1){
							cout<<v[i][v_idx++]<<fst_char<<" "<<v[i][v_idx++]<<fst_char<<"\n";
						}
					}
				}
			}
			while(idx<v[c-'A'].size()){
				cout<<v[c-'A'][idx++]<<c<<" "<<v[c-'A'][idx++]<<c<<"\n";
			}
		}
	}
	return 0;
}