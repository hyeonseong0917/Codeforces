#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
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
		string s;
		cin>>n;
		cin>>s;
		string prev_str="";
		string lex_str="";
		for(int i=0;i<n-1;++i){
			if(s[i]>s[i+1]){
				lex_str+=s[i];
			}else{
				prev_str+=s[i];
			}
		}
		prev_str+=s[n-1];
		int cnt=1;
		for(int i=n-1;i>=1;--i){
			if(s[i]==s[i-1]){
				++cnt;
			}else{
				break;
			}
		}
		prev_str=prev_str.substr(0,prev_str.size()-cnt);
		if(lex_str.size()==0){
			cout<<0<<"\n";
			continue;
		}
		for(int i=0;i<cnt;++i){
			lex_str+=s[n-1];
		}
		int ans=lex_str.size()-1;
			cout<<prev_str<<endl;
			cout<<lex_str<<endl;
		string new_str="";
		reverse(lex_str.begin(),lex_str.end());
		new_str+=prev_str;
		new_str+=lex_str;
		bool flag=0;
		cout<<new_str<<"\n";
		for(int i=0;i<new_str.size()-1;++i){
			if(new_str[i]>new_str[i+1]){
				flag=1;
				break;
			}
		}
		
		if(flag){
			cout<<-1<<"\n";
		}else{
			cout<<ans<<"\n";
		}
	}	
	return 0;
}