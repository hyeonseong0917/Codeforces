#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool comp(pair<int,int> a, pair<int,int> b){
	return a.second>b.second;
}
bool cmp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
	return a.first<b.first;
}
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		int n=0;
		cin>>n;
		vector<pair<int,int>> v;
		vector<pair<int,pair<int,int>>> ans;
		for(int i=0;i<n;++i){
			int a=0;
			cin>>a;
			v.push_back({i,a}); //a값이 i인덱스에 존재
		}
		map<int,int> m;
		sort(v.begin(),v.end(),comp); //a값 기준으로 내림차순 정렬됨
		for(int i=0;i<v.size();++i){
			ans.push_back({v[i].first,{v[i].second, i+1}}); //
		}
		sort(ans.begin(),ans.end(),cmp);
		for(int i=0;i<v.size();++i){
			cout<<ans[i].second.second<<" ";
		}
		cout<<"\n";
		cout<<"\n";
	}
	return 0;
}