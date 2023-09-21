#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

#define ll long long

const int MAX=200000+5;

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	map<char,int> first_str, second_str;
	while(t--){
		int n=0;
		first_str.clear();
		second_str.clear();
		cin>>n;
		string s;
		cin>>s;
		for(int i=0;i<s.size();++i){
			++first_str[s[i]];
		}
		int total_sum=0;
		
		for(int i=0;i<s.size();++i){
			--first_str[s[i]];
			++second_str[s[i]];
			int cur_sum=0;
			for(int j=0;j<26;++j){
				cur_sum+=min(1,first_str['a'+j])+min(1,second_str['a'+j]);
			}
			total_sum=max(total_sum,cur_sum);
		}
		cout<<total_sum<<"\n";
		cout<<"\n";
	}
	return 0;
}