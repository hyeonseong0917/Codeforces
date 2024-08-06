#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		stack<ll> st;
		string s;
		cin>>s;
		ll ans=0;
		for(ll i=0;i<n;++i){
			if(s[i]=='_'){
				if(st.empty()){
					st.push(i);
				}else{
					ans+=(i-st.top());
					st.pop();
				}
			}else if(s[i]=='('){
				st.push(i);
			}else{
				ans+=(i-st.top());
				st.pop();
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}