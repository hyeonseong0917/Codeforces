#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

bool comp(pair<int,int> a, pair<int,int> b){
	if(a.first==b.first){
		return a.second>b.second;
	}
	return a.first<b.first;
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=1;
	while(t--){
		string s;
		cin>>s;
		int n=s.size();
		vector<pair<int,int>> p;
		int open_num=0, closed_num=0;
		p.push_back({0,0});
		if(s[0]=='('){
			++open_num;
		}else{
			++closed_num;
		}
		for(int i=1;i<n;++i){
			p.push_back({open_num-closed_num,i});
			if(s[i]=='('){
				++open_num;
			}else{
				++closed_num;
			}	
		}
		sort(p.begin(),p.end(),comp);
		for(int i=0;i<p.size();++i){
			cout<<s[p[i].second];
		}
	}
	
	return 0;
}