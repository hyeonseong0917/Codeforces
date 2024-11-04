#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o;
	cin>>o;
	while(o--){
		string s;
		cin>>s;
		if(s.size()<=2){
			cout<<"NO"<<"\n";
		}else{
			string tmp=s.substr(0,2);
			if(tmp!="10"){
				cout<<"NO"<<"\n";
			}else{
				ll n=s.size();
				string rest=s.substr(2,n-2);
				ll rest_num=stoll(rest);
				if(rest[0]=='0' || rest_num<2){
					cout<<"NO"<<"\n";
				}else{
					cout<<"YES"<<"\n";
				}
			}
		}
	}
	return 0;
}