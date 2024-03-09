#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		stack<int> lower_point, upper_point;
		for(int i=0;i<s.size();++i){
			if(s[i]=='B' || s[i]=='b'){
				if(s[i]=='B' && !upper_point.empty()){
					upper_point.pop();
				}
				if(s[i]=='b' && !lower_point.empty()){
					lower_point.pop();
				}
			}else{
				if('A'<=s[i] && s[i]<='Z'){
					upper_point.push(i);
				}else{
					lower_point.push(i);
				}
			}
		}
		vector<int> v;
		while(!lower_point.empty()){
			int cur_num=lower_point.top();
			v.push_back(cur_num);
			lower_point.pop();
		}
		while(!upper_point.empty()){
			int cur_num=upper_point.top();
			v.push_back(cur_num);
			upper_point.pop();
		}
		sort(v.begin(),v.end());
		string ans="";
		for(int i=0;i<v.size();++i){
			ans+=s[v[i]];
		}
		cout<<ans<<"\n";
	}
	return 0;
}