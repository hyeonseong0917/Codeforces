#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
ll lcm(ll a, ll b){
	return (a*b)/gcd(a,b);
}
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n,x;
		cin>>n>>x;
		vector<ll> v(n,0);
		ll sum=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			sum+=v[i];
		}
		sort(v.begin(),v.end());
		if(v[0]>=x){
			cout<<sum<<"\n";
			for(ll i=0;i<n;++i){
				cout<<v[i]<<" ";
			}	
			cout<<"\n";
			continue;
		}
		vector<ll> ans;
		ll L=0, R=n-1;
		sum=0;
		ll score=0;
		// 0 1 2 3 4 5 6 7 8 9
		// 1 1 1 1 1 2 2 2 2 2
		// 

		while(L<=R){	
			// 만약 R을 더했을 때 [S/X] 값이 바뀐다면 R을 넣기
			// 아니라면 L넣기
			ll cur_num=sum/x;
			ll next_num=(sum+v[R])/x;
			if(cur_num<next_num){
				sum+=v[R];
				score+=v[R];
				ans.push_back(v[R--]);
			}else{
				sum+=v[L];
				ans.push_back(v[L++]);
			}
		}
		cout<<score<<"\n";
		for(ll i=0;i<n;++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";
	} 
	return 0;
}