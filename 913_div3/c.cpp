#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <stack>
using namespace std;

int dp[100000+1];
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		int N;
		string s;
		cin>>N;
		cin>>s;
		int arr[26+1];
		for(int i=0;i<26;++i){
			arr[i]=0;
		}
		for(int i=0;i<N;++i){
			++arr[s[i]-'a'];
		}
		int max_num=0;
		char max_char;
		for(int i=0;i<26;++i){
			max_num=max(max_num,arr[i]);
		}
		if(max_num>(N/2)){
			cout<<max_num-(N-max_num)<<"\n";
		}else{
			if(N%2==0){
				cout<<0<<"\n";
			}else{
				cout<<1<<"\n";
			}
		}
	}
	return 0;
}