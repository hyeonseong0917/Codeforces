#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<pair<int,int>> v;
		for(int i=0;i<n;++i){
			int a=0;
			cin>>a;
			v.push_back({a,0});
		}
		for(int i=0;i<n;++i){
			int a=0;
			cin>>a;
			v[i].second=a;
		}
		sort(v.begin(),v.end());
		for(int i=0;i<n;++i){
			cout<<v[i].first<<" ";
		}cout<<"\n";
		for(int i=0;i<n;++i){
			cout<<v[i].second<<" ";
		}cout<<"\n";
	}	
	return 0;
}