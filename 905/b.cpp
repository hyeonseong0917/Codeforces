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

	while(t--){
		int n,k;
		cin>>n>>k;
		string s;
		vector<char> v;
		map<char,int> m;
		cin>>s;
		for(int i=0;i<s.size();++i){
			if(!m[s[i]]){
				m[s[i]]=1;
				v.push_back(s[i]);
			}else{
				++m[s[i]];
			}
		}
		int cnt=0;
		for(int i=0;i<v.size();++i){
			if(m[v[i]]%2==1){
				++cnt;
			}
		}
		if(cnt-1<=k){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}

	}	
	return 0;
}