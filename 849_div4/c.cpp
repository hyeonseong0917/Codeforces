#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int n=0;
		cin>>n;
		string s;
		cin>>s;
		int L=0, R=s.size()-1;
		int cnt=s.size();
		while(L<R){
			if(s[L]!=s[R]){
				++L;
				--R;
				cnt-=2;
			}else{
				break;
			}
		}
		cout<<cnt<<"\n";
		cout<<"\n";
		
	}
	return 0;
}