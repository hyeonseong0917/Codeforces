#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long

const int MAX=1000+1;

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
		vector<ll> v;
		bool flag=0;
		ll sum=1;
		for(int i=0;i<n;++i){
			ll a=0;
			cin>>a;
			if(a%k==0){
				flag=1;
			}
			v.push_back(a);
		}
		if(flag){
			cout<<0<<"\n";
			continue;
		}
		ll min_num=122232421;
		for(int i=0;i<v.size();++i){
			min_num=min(min_num,k-(v[i]%k));
		}
		if(k==4){
			ll cnt=0;
			ll cur_num=122232421;
			for(int i=0;i<v.size();++i){
				if(v[i]%2==0){
					++cnt;
				}
			}
			cur_num=max((ll)0,(ll)(2-cnt));
			min_num=min(min_num,cur_num);
		}
		
		cout<<min_num<<"\n";
		
	}	
	return 0;
}