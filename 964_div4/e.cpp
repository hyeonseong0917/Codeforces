#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long

vector<ll> p(200000+1,0);
void Init(){
	for(ll i=1;i<=200000;++i){
		ll cur_num=i;
		ll cnt=0;
		while(cur_num){
			cur_num/=3;
			++cnt;
		}
		p[i]=cnt;
	}
	for(ll i=1;i<=200000;++i){
		p[i]+=p[i-1];
	}
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Init();
	ll o;
	cin>>o;
	while(o--){
		ll l,r;
		cin>>l>>r;
		ll q=l;
		ll ans=0;
		while(q){
			q/=3;
			++ans;
		}
		ans*=2;
		ans+=p[r]-p[l];
		cout<<ans<<"\n";
	}
	return 0;
}