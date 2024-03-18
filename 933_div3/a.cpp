#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int n;
		string s;
		cin>>n;
		cin>>s;
		int cnt=0;
		int i=1;
		while(i<s.size()-1){
			if((s[i]=='a' && s[i-1]=='m' && s[i+1]=='p') || (s[i]=='i' && s[i-1]=='p' && s[i+1]=='e')){
				if(s[i]=='a' && i+3<=s.size()-1){
					if(s.substr(i-1,5)=="mapie"){
						++cnt;
						i+=4;
						continue;
					}
				}
				++cnt;
			}

			++i;
		}
		
		cout<<cnt<<"\n";
	}
	return 0;
}