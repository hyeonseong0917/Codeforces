#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//1021
bool comp(pair<int,string> a, pair<int,string> b){
	return a.first<b.first;
}
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int n=0;
		cin>>n;
		int cnt=0;
		vector<pair<int,string>> v;
		for(int i=0;i<n;++i){
			int m=0;
			string s="";
			cin>>m>>s;
			v.push_back({m,s});
		}
		// 3 10
		// 7 11
		
		sort(v.begin(),v.end(),comp);
		bool next=0;
		int firstNum=122232421;
		for(int i=0;i<n;++i){
			if(v[i].second=="11"){
				firstNum=v[i].first;
				next=1;
				break;
			}
		}
		
		bool good=0;
		
		for(int i=0;i<n;++i){
			string cur_str=v[i].second;
			
			if(cur_str[0]=='1'){
				cnt+=v[i].first;
				good=1;
				if(cur_str[1]=='1'){
					
				}
				break;
			}
		}
		if(!good){
			
			cout<<-1<<endl;
			continue;
		}
		bool second_good=0;
		for(int i=0;i<n;++i){
			string cur_str=v[i].second;
			if(cur_str[1]=='1'){
				cnt+=v[i].first;
				second_good=1;
				break;
			}
		}
		if(!second_good){
			cout<<-1<<endl;
			continue;
		}
		cout<<min(cnt,firstNum)<<endl;
	}
	return 0;
}