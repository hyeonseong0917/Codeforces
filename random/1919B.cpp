#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
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
		cin>>n;
		string s;
		cin>>s;
		int plus_cnt=0, minus_cnt=0;
		for(int i=0;i<n;++i){
			if(s[i]=='+'){
				++plus_cnt;
			}else{
				++minus_cnt;
			}
		}
		cout<<abs(plus_cnt-minus_cnt)<<"\n";
	}
	return 0;
}