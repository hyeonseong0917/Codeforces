#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
//1017
#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		string a,b;
		string tmp;
		cin>>a;
		cin>>b;
		if(b.size()>a.size()){
			tmp=a;
			a=b;
			b=tmp;
		}
		if(a[0]==b[0]){
			cout<<"YES"<<"\n";
			string ans=a.substr(0,1)+"*";
			cout<<ans<<"\n";
			continue;
		}
		if(a[a.size()-1]==b[b.size()-1]){
			cout<<"YES"<<"\n";
			string ans="*"+a.substr(a.size()-1,1);
			cout<<ans<<"\n";
			continue;
		}
		if(b.size()==1){
			cout<<"NO"<<"\n";
			continue;
		}
		// 길이가 2인 substring
		string template_str="";
		for(int i=0;i<=b.size()-2;++i){
			string cur_substr=b.substr(i,2);
			for(int j=0;j<=a.size()-2;++j){
				string next_substr=a.substr(j,2);
				if(cur_substr==next_substr){
					template_str=next_substr;
					break;
				}
			}
		}
		if(template_str!=""){
			cout<<"YES"<<"\n";
			cout<<"*"<<template_str<<"*"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
		
		
	}
	return 0;
}