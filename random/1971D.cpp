#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n=s.size();
		int idx=0;
		string tmp_str="";
		vector<string> v;
		while(idx<n){
			if(!tmp_str.empty() && tmp_str[tmp_str.size()-1]>s[idx]){
				v.push_back(tmp_str);
				tmp_str="";
			}else{
				tmp_str+=s[idx++];
			}
		}
		if(!tmp_str.empty()){
			v.push_back(tmp_str);
		}
		int cnt=v.size();
		bool flag=0;
		for(int i=0;i<v.size();++i){
			string cur_str=v[i];
			bool is_all_same=1;
			for(int i=0;i<cur_str.size();++i){
				if(cur_str[i]!=cur_str[0]){
					is_all_same=0;
					break;
				}
			}
			if(is_all_same) continue;
			if(!flag){
				flag=1;
			}else{
				++cnt;
			}
		}
		cout<<cnt<<"\n";
	}
	
	return 0;
}