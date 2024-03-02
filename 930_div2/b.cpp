#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	char board[2][200000+1];
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<2;++i){
			for(int j=0;j<n;++j){
				cin>>board[i][j];
			}
		}
		int L=0;
		int R=n-1;
		string s="";
		for(int i=n-1;i>=1;--i){
			if(board[0][i]=='1' && board[1][i-1]=='0'){
				R=i-1;
			}
		}
		for(int i=0;i<R;++i){
			if(board[0][i+1]=='0' && board[1][i]=='1'){
				L=i+1;
			}
		}
		// cout<<L<<" "<<R<<"\n";
		for(int i=0;i<=L;++i){
			s+=board[0][i];
		}
		for(int i=L;i<n;++i){
			s+=board[1][i];
		}
		cout<<s<<"\n";
		cout<<R-L+1<<"\n";
	}	
	return 0;
}