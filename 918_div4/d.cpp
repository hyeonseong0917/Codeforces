#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

#define ll long long

const int MAX=200000+5;

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
		string t="";
		for(int i=0;i<n;++i){
			if(s[i]=='a' || s[i]=='e'){
				t+='V';
			}else{
				t+='C';
			}
		}
		if(n==1 || n==2 || n==3){
			cout<<s<<"\n";
		}else{
			int idx=0;
			while(1){
				if(idx==n-3 || idx==n-2){
					for(int i=idx;i<n;++i){
						cout<<s[i];
					}cout<<"\n";
					break;
				}
				if(t[idx+3]=='C'){
					for(int i=idx;i<idx+3;++i){
						cout<<s[i];
					}cout<<'.';
					idx+=3;
				}else{
					for(int i=idx;i<idx+2;++i){
						cout<<s[i];
					}cout<<'.';
					idx+=2;
				}
			}
		}
	}
	return 0;
}