#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int o=1;
	cin>>o;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		ll max_num=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			max_num=max(max_num,v[i]);
		}
		if(max_num==0){
			for(ll i=0;i<n+1;++i){
				if(i%2==0){
					cout<<"a"<<"\n";
				}else{
					cout<<"b"<<"\n";
				}
			}
			continue;
		}
		string fst_str="";
		for(ll i=0;i<max_num;++i){
			fst_str+='a';
		}
		vector<string> ans;
		ans.push_back(fst_str);
		for(ll i=0;i<n;++i){
			string sed_str=ans[i];
			for(ll j=v[i];j<max_num;++j){
				if(sed_str[j]=='a'){
					sed_str[j]='b';
				}else{
					sed_str[j]='a';
				}
			}
			ans.push_back(sed_str);
		}
		for(ll i=0;i<n+1;++i){
			cout<<ans[i]<<"\n";
		}
	} 

	return 0;
}