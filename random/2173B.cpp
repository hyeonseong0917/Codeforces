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
		vector<ll> a(n,0), b(n,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		for(ll i=0;i<n;++i){
			cin>>b[i];
		}
		ll max_num=0, min_num=0;
		for(ll i=0;i<n;++i){
			vector<ll> v;
			v.push_back(max_num-a[i]);
			v.push_back(b[i]-max_num);

			v.push_back(min_num-a[i]);
			v.push_back(b[i]-min_num);
			sort(v.begin(),v.end());
			max_num=v[3];
			min_num=v[0];
			// cout<<i<<" "<<min_num<<" "<<max_num<<endl;
		}
		cout<<max_num<<"\n";
	} 

	return 0;
}