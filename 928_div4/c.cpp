#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long

const int MAX=200000+1;
int s[MAX];
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	for(int i=0;i<MAX;++i){
		s[i]=0;
	}
	for(int i=1;i<MAX;++i){
		// int tmp=i;
		// int cur_num=0;
		// while(tmp){
		// 	cur_num+=tmp%10;
		// 	tmp/=10;
		// }
		string t=to_string(i);
		for(int j=0;j<t.size();++j){
			s[i]+=t[j]-'0';
		}
		s[i]+=s[i-1];
	}
	int t=0;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		
		cout<<s[n]<<"\n";
	}	
	return 0;
}