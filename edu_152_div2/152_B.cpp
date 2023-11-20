#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
vector<int> a;
vector<pair<int,int>> v;
bool comp(pair<int,int> a, pair<int,int> b){
	if(a.first==b.first){
		return a.second<b.second;
	}
	return a.first>b.first;
}
int main(){
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		a.clear();
		v.clear();
		int n,k;
		cin>>n>>k;
		for(int i=0;i<n;++i){
			int c=0;
			cin>>c;
			if(c%k==0){
				a.push_back(i+1);
			}else{
				v.push_back({c%k,i});	
			}
			
		}
		sort(v.begin(),v.end(),comp);
		for(int i=0;i<v.size();++i){
			a.push_back(v[i].second+1);
		}
		for(int i=0;i<n;++i){
			cout<<a[i]<<" ";
		}
		cout<<"\n";

		
	}
	return 0;
}