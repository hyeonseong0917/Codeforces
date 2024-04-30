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
		vector<string> s;
		int one_cnt=0;
		cin>>n;
		for(int i=0;i<n;++i){
			string t;
			cin>>t;
			s.push_back(t);
		}
		
		bool is_square=1;
		for(int i=0;i<n-1;++i){
			for(int j=0;j<n-1;++j){
				int one_cnt=0;
				if(s[i][j]=='1') ++one_cnt;
				if(s[i][j+1]=='1') ++one_cnt;
				if(s[i+1][j]=='1')  ++one_cnt;
				if(s[i+1][j+1]=='1') ++one_cnt;
				if(one_cnt==3){
					is_square=0;
				}
			}
		}
		if(is_square){
			cout<<"SQUARE"<<"\n";
		}else{
			cout<<"TRIANGLE"<<"\n";
		}
	}	
	return 0;
}