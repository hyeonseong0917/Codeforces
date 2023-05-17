#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int,pair<int,int>> x, pair<int,pair<int,int>> y){
	return x.second.second>y.second.second;
}
int main() {
	// your code goes here 1301

	int q=0;
	int n,t=0;
	cin>>q;
	while(q--){
		cin>>n>>t;
		vector<int> a,b;
		vector<pair<int,pair<int,int>>> v;
		bool flag=0;
		for(int i=0;i<n;++i){
			int c=0;
			cin>>c;
			if(c<=t){
				flag=1;
			}
			a.push_back(c);
		}
		for(int i=0;i<n;++i){
			int c=0;
			cin>>c;
			b.push_back(c);
		}
		if(flag==0){
			cout<<-1<<endl;
			continue;
		}
		
		for(int i=0;i<n;++i){
			v.push_back({i,{a[i],b[i]}});
		}
		sort(v.begin(),v.end(),comp);
		bool check=0;
		for(int i=0;i<n;++i){
			if(v[i].first+v[i].second.first<=t){
				cout<<v[i].first+1<<endl;
				check=1;
				break;
			}
		}
		if(!check){
			cout<<-1<<endl;
		}
	}
	return 0;
}