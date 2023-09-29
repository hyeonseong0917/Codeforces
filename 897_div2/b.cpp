#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define ll long long

const int MAX=50+5;
bool comp(vector<int> a, vector<int> b){
	return a.size()>b.size();
}
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	int n=0;
	vector<vector<int>> A;
	while(t--){
		map<int,int> U;
		int n=0;
		cin>>n;
		for(int i=0;i<n;++i){
			int k=0;
			vector<int> tmp;
			cin>>k;
			tmp.push_back(k);
			for(int t=0;t<k;++t){
				int a=0;
				cin>>a;
				tmp.push_back(a);
				U[a]=1;
			}
			A.push_back(tmp);
		}
		if(n==1){
			cout<<0<<"\n";
			continue;
		}
		sort(A.begin(),A.end(),comp);
		int max_num=0;
		for(int i=0;i<n;++i){
			vector<int> cur_vector=A[i];
			map<int,int> cur_map;
			for(int j=0;j<n;++j){
				if(i==j) continue;
				vector<int> rest_vector=A[j];
				for(int k=0;k<rest_vector.size();++k){
					cur_map[rest_vector[k]]=1;
				}
			} 
			if(cur_map.size()==U.size()) continue;
			int cs=cur_map.size();
			max_num=max(max_num,cs);
		}
		cout<<max_num<<"\n";
		cout<<"\n";
	}
	return 0;
}