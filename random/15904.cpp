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
	int t=1;
	while(t--){
		string s;
		vector<char> v;
		v.push_back('U');
		v.push_back('C');
		v.push_back('P');
		v.push_back('C');
		ll idx=0;
		while(cin>>s){
			for(ll i=0;i<s.size();++i){
				if(idx==4) break;
				if(s[i]==v[idx]){
					++idx;
				}
			}
		}
		if(idx==4){
			cout<<"I love UCPC";
		}else{
			cout<<"I hate UCPC";
		}

	}
	return 0;
}