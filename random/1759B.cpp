#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll m,s;
		cin>>m>>s;
		vector<ll> v(m,0);
		ll cur_sum=0;
		for(ll i=0;i<m;++i){
			cin>>v[i];
			cur_sum+=v[i];
		}
		sort(v.begin(),v.end());
		ll max_num=v[m-1];
		ll diff=((max_num*(max_num+1))/2-cur_sum);
		s-=diff;
		// 2 1
		// 4 3
		bool flag=0;
		for(ll i=max_num+1;i<=1000;++i){
			if(s==0){
				flag=1;
				break;
			}
			s-=i;
			if(s<0){
				break;
			}
		}
		if(s==0){
			flag=1;
		}
		if(flag){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
	} 
	return 0;
}