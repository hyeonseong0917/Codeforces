#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

int dp[100000+1];
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	
	vector<int> v;
	while(t--){
		v.clear();
		int n=0;
		cin>>n;
		string s;
		cin>>s;
		reverse(s.begin(),s.end());
		// 00110 -> 01100
		// v=[0,3,4]
		// 0000111 -> 1110000
		// v=[3,4,5,6]
		// i인덱스 전에 있는 0들을 
		for(int i=0;i<n;++i){
			if(s[i]=='0'){
				v.push_back(i);
			}
		}
		long long sum=0;
		for(int i=0;i<n;++i){
			if(i<v.size()){
				sum+=v[i]-i;
				
				cout<<sum<<" ";
			}else{
				cout<<-1<<" ";
			}
		}cout<<"\n";

	}
	return 0;
}