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
	ll o=1;
	cin>>o;
	while(o--){
		ll n;
		cin>>n;
		string s,t;
		cin>>s;
		cin>>t;
		string k=s;
		reverse(k.begin(),k.end());
		ll origin_num=0;
		ll reverse_num=0;
		for(ll i=0;i<n;++i){
			if(t[i]!=s[i]){
				++origin_num;
			}
			if(t[i]!=k[i]){
				++reverse_num;
			}
		}
		if(origin_num==0){
			cout<<0<<"\n";
			continue;
		}
		if(origin_num%2==1){
			origin_num=(origin_num-1)*2+1;
		}else{
			origin_num*=2;
		}
		if(reverse_num==0){
			cout<<min((ll)2,origin_num)<<"\n";
			continue;
		}
		if(reverse_num%2==1){
			reverse_num*=2;
		}else{
			reverse_num=(reverse_num-1)*2+1;
		}
		cout<<min(origin_num,reverse_num)<<"\n";
	}
	return 0;
}