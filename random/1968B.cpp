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
		int n,m;
		cin>>n>>m;
		string a,b;
		cin>>a;
		cin>>b;
		int a_idx=0;
		int b_idx=0;
		while(1){
			if(a_idx==n || b_idx==m){
				break;
			}
			if(a[a_idx]==b[b_idx]){
				++a_idx;
				++b_idx;
			}else{
				++b_idx;
			}
		}
		cout<<a_idx<<"\n";
	}
	return 0;
}