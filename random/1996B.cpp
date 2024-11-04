#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		// n*n, 0과 1로 이루어짐
		ll n,k;
		cin>>n>>k;
		ll m=n/k;
		vector<string> s;
		for(ll i=0;i<n;++i){
			string tmp="";
			cin>>tmp;
			s.push_back(tmp);
		}
		vector<string> ans;
		for(ll i=0;i<n;i+=k){
			string cur_ans="";
			for(ll j=0;j<n;j+=k){
				cur_ans+=s[i][j];
			}
			ans.push_back(cur_ans);
		}
		ll as=ans.size();
		for(ll i=0;i<as;++i){
			cout<<ans[i]<<"\n";
		}
	} 
	return 0;
}