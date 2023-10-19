#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long

const int MAX=1000+1;

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	string board[MAX];
	int t=0;
	cin>>t;
	vector<char> edge;
	vector<string> middle;
	while(t--){
		int n,m;
		cin>>n>>m;
		string x,s;
		cin>>x;
		cin>>s;
		// 언제 s가 x의 substring이 될까?
		bool flag=0;
		int cnt=0;
		string cur_string="";
		bool c=0;
		while(1){
			if(flag){
				break;
			}
			if(x.size()>200){
				break;
			}
			if(x.size()<s.size()){
				x+=x;
				++cnt;
				continue;
			}
			for(int i=0;i<=x.size()-s.size();++i){
				string tmp="";
				for(int j=0;j<s.size();++j){
					tmp+=x[i+j];
				}
				if(tmp.compare(s)==0){
					flag=1;
				}
			}
			if(!flag){
				x+=x;
				++cnt;
			}
		
		}
		if(flag){
			cout<<cnt<<"\n";	
		}else{
			cout<<-1<<"\n";
		}
		
		
	}	
	return 0;
}