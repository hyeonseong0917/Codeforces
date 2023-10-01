#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		string s="";
		cin>>s;
		string ans="";
		bool flag=0;
		for(int i=0;i<n;++i){
			if(s[i]-'0'<=d){
				if(s[i]-'0'==d && i!=n-1){
					if(s[i]<=s[i+1]){
						continue;
					}
				}
				ans+=s.substr(0,i);
				ans+=(d+'0');
				ans+=s.substr(i,n-(i)+1);
				flag=1;
				break;
			}
		}
		if(!flag){
			s+=(d+'0');
			ans=s;
		}
		cout<<ans<<"\n";
		// cout<<"\n";
	}
	return 0;
}