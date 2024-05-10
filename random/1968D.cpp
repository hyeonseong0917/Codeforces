#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n,k,pb,ps;
		cin>>n>>k>>pb>>ps;
		vector<ll> p(n,0), a(n,0);
		for(ll i=0;i<n;++i){
			cin>>p[i];
		}
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		// b먼저
		vector<ll> bp, ba(n,0), bsum(n,0);
		bp.push_back(pb);
		while(1){
			ll bps=bp.size();
			if(bps==n){
				break;
			}
			bp.push_back(p[bp[bps-1]-1]);
		}
		for(ll i=0;i<n;++i){
			ba[i]=a[bp[i]-1];
		}
		bsum[0]=ba[0];
		for(ll i=1;i<n;++i){
			bsum[i]=bsum[i-1]+ba[i];
		}
		ll max_b=0;
		for(ll i=0;i<n;++i){
			max_b=max(max_b,bsum[i]+ba[i]*(k-i-1));
			if((k-i-1)==0){
				break;
			}
		}
		// cout<<"fds"<<max_b<<endl;
		ll bnum=(k/n)*bsum[n-1];
		if(k%n!=0){
			// cout<<bsum[k%n]<<"\n";
			bnum+=bsum[k%n-1];
		}
		bnum=max(bnum,max_b);
		// cout<<bnum<<endl;
		// s진행
		// b먼저
		vector<ll> sp, sa(n,0), ssum(n,0);
		sp.push_back(ps);
		while(1){
			ll bps=sp.size();
			if(bps==n){
				break;
			}
			sp.push_back(p[sp[bps-1]-1]);
		}
		for(ll i=0;i<n;++i){
			sa[i]=a[sp[i]-1];
		}
		ssum[0]=sa[0];
		for(ll i=1;i<n;++i){
			ssum[i]=ssum[i-1]+sa[i];
		}
		ll max_s=0;
		for(ll i=0;i<n;++i){
			max_s=max(max_s,ssum[i]+sa[i]*(k-i-1));
			if((k-i-1)==0){
				break;
			}
			// cout<<i<<" "<<max_s<<endl;
		}
		// cout<<max_s<<endl;
		ll snum=(k/n)*ssum[n-1];
		if(k%n!=0){
			// cout<<bsum[k%n]<<"\n";
			snum+=ssum[k%n-1];
		}
		snum=max(snum,max_s);
		
		if(bnum>snum){
			cout<<"Bodya"<<"\n";
		}else if(bnum<snum){
			cout<<"Sasha"<<"\n";
		}else{
			cout<<"Draw"<<"\n";
		}
	}
	
	return 0;
}