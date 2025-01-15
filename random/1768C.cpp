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
		ll n;
		cin>>n;
		vector<ll> v(n,0), p(n,0), q(n,0);
		map<ll,ll> check;
		bool flag=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			++check[v[i]];
			if(check[v[i]]>=3){
				flag=1;
			}
		}
		if(flag || check[1]==2){
			cout<<"NO"<<"\n";
			continue;
		}
		if(n==1){
			cout<<"YES"<<"\n";
			cout<<1<<"\n";
			cout<<1<<"\n";
			continue;
		}
		vector<ll> double_num,no_num;
		map<ll,ll> double_check;
		vector<ll> double_num_idx[n+1];
		for(ll i=0;i<n;++i){
			if(check[v[i]]==1){
				p[i]=v[i];
				q[i]=v[i];
			}
			if(check[v[i]]==2 && !double_check[v[i]]){
				double_check[v[i]]=1;
				double_num.push_back(v[i]);
			}
			if(check[v[i]]==2){
				// cout<<i<<endl;
				double_num_idx[v[i]].push_back(i);
			}
		}
		for(ll i=1;i<=n;++i){
			if(!check[i]){
				no_num.push_back(i);
			}
		}
		sort(double_num.begin(),double_num.end());
		sort(no_num.begin(),no_num.end());
		flag=0;
		for(ll i=0;i<double_num.size();++i){
			if(double_num[i]<no_num[i]){
				flag=1;
				break;
			}
			ll fst_idx=double_num_idx[double_num[i]][0];
			ll sed_idx=double_num_idx[double_num[i]][1];
			p[fst_idx]=double_num[i];
			q[fst_idx]=no_num[i];
			p[sed_idx]=no_num[i];
			q[sed_idx]=double_num[i];
		}
		if(flag){
			cout<<"NO"<<"\n";
		}else{
			cout<<"YES"<<"\n";
			for(ll i=0;i<n;++i){
				cout<<p[i]<<" ";
			}cout<<"\n";
			for(ll i=0;i<n;++i){
				cout<<q[i]<<" ";
			}cout<<"\n";
		}
		
	} 
	return 0;
}