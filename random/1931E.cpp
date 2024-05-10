#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define ll long long
bool comp(pair<int,int> a, pair<int,int> b){
	return a.second>b.second;
}
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<int> v(n,0);
		vector<pair<int,int>> p;
		for(int i=0;i<n;++i){
			cin>>v[i];
			string s=to_string(v[i]);
			int cnt=0;
			for(int j=s.size()-1;j>=0;--j){
				if(s[j]=='0'){
					++cnt;
				}else{
					break;
				}
			}
			p.push_back({v[i],cnt});
		}
		sort(p.begin(),p.end(),comp);
		stack<string> st;
		int idx=0;
		while(idx<n){
			// reverse 할 거 찾기
			int cur_num=p[idx].first;
			string cur_num_str=to_string(cur_num);
			reverse(cur_num_str.begin(),cur_num_str.end());
			int reversed_cur_num=stoi(cur_num_str);
			st.push(to_string(reversed_cur_num));
			++idx;
			if(idx==n){
				break;
			}
			// concat 할 거 찾기
			int next_num=p[idx].first;
			string next_num_str=to_string(next_num);
			string cur_front_str=st.top();
			st.pop();
			next_num_str+=cur_front_str;
			// cout<<cur_front_str<<" "<<next_num_str<<endl;
			st.push(next_num_str);

			++idx;
		}
		int k=0;
		while(!st.empty()){
			string cur_num=st.top();
			// cout<<cur_num<<endl;
			st.pop();
			k+=cur_num.size();
		}
		--k;
		if(k>=m){
			cout<<"Sasha"<<"\n";
		}else{
			cout<<"Anna"<<"\n";
		}
	}
	
	return 0;
}