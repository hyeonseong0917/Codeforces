#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		string s[n+1];
		for(int i=0;i<n;++i){
			cin>>s[i];
		}
		char cur_color=s[n-1][m-1];
		if(cur_color==s[0][0] || s[n-1][0]== s[0][m-1]){
			cout<<"YES"<<"\n";
			continue;
		}
		bool fst_flag=0;
		for(int i=0;i<n;++i){
			if(s[i][0]==cur_color){
				fst_flag=1;
				break;
			}
		}
		bool sed_flag=0;
		for(int i=0;i<m;++i){
			if(s[0][i]==cur_color){
				sed_flag=1;
				break;
			}
		}
		if(fst_flag && sed_flag){
			cout<<"YES"<<"\n";
		}else{
			fst_flag=0, sed_flag=0;
			cur_color=s[n-1][0];
			for(int i=0;i<n;++i){
				if(s[i][m-1]==cur_color){
					fst_flag=1;
				}
			}
			for(int i=0;i<m;++i){
				if(s[0][i]==cur_color){
					sed_flag=1;
				}
			}
			if(fst_flag && sed_flag){
				cout<<"YES"<<"\n";
			}else{
				fst_flag=0, sed_flag=0;
				cur_color=s[0][0];
				for(int i=0;i<n;++i){
					if(s[i][m-1]==cur_color){
						fst_flag=1;
					}
				}
				for(int i=0;i<m;++i){
					if(s[n-1][i]==cur_color){
						sed_flag=1;
					}
				}	
				if(fst_flag && sed_flag){
					cout<<"YES"<<"\n";
				}else{
					fst_flag=0, sed_flag=0;
					cur_color=s[0][m-1];
					for(int i=0;i<n;++i){
						if(s[i][0]==cur_color){
							fst_flag=1;
						}
					}
					for(int i=0;i<m;++i){
						if(s[n-1][i]==cur_color){
							sed_flag=1;
						}
					}	
					if(fst_flag && sed_flag){
						cout<<"YES"<<"\n";
					}else{
						cout<<"NO"<<"\n";
					}
				}
			}

		}
	}
	
	return 0;
}