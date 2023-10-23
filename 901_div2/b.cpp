#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		vector<ll> J,G;
		ll n,m,k;
		cin>>n>>m>>k;
		for(int i=0;i<n;++i){
			ll c=0;
			cin>>c;
			J.push_back(c);
		}
		for(int i=0;i<m;++i){
			ll c=0;
			cin>>c;
			G.push_back(c);
		}
		sort(J.begin(),J.end());
		sort(G.begin(),G.end());
		vector<ll> first_J, first_G, second_J, second_G;
		//first_J
		if(J[0]<G[m-1]){
			first_J.push_back(G[m-1]);
			for(int i=1;i<n;++i){
				first_J.push_back(J[i]);
			}
			first_G.push_back(J[0]);
			for(int i=0;i<m-1;++i){
				first_G.push_back(G[i]);
			}
		}else{
			first_J=J;
			first_G=G;
		}
		sort(first_J.begin(),first_J.end());
		sort(first_G.begin(),first_G.end());
		//second_J G공격
		if(first_G[0]<first_J[n-1]){
			second_G.push_back(first_J[n-1]);
			for(int i=1;i<m;++i){
				second_G.push_back(first_G[i]);
			}
			second_J.push_back(first_G[0]);
			for(int i=0;i<n-1;++i){
				second_J.push_back(first_J[i]);
			}
		}else{
			second_J=first_J;
			second_G=first_G;
		}
		// for(int i=0;i<n;++i){
		// 	cout<<first_J[i]<<" ";
		// }cout<<endl;
		// for(int i=0;i<n;++i){
		// 	cout<<second_J[i]<<" ";
		// }cout<<endl;
		ll sum=0;
		if(k%2==1){
			for(int i=0;i<n;++i){
				sum+=first_J[i];
			}	
		}else{
			for(int i=0;i<n;++i){
				sum+=second_J[i];
			}	
		}
		
		// if(J[0]<G[G.size()-1]){
		// 	if(k%2==1){
		// 		sum+=G[G.size()-1];
		// 		for(int i=1;i<n;++i){
		// 			sum+=J[i];
		// 		}
		// 	}else{
		// 		for(int i=0;i<n;++i){
		// 			sum+=J[i];
		// 		}
		// 	}
		// }else{
		// 	if(k%2==1){
		// 		for(int i=0;i<n;++i){
		// 			sum+=J[i];
		// 		}	
		// 	}else{
		// 		sum+=G[0];
		// 		for(int i=0;i<n-1;++i){
		// 			sum+=J[i];
		// 		}
		// 	}
		// }
		cout<<sum<<"\n";
		cout<<"\n";
	}	
	return 0;
}