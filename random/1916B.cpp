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
		string s;
		cin>>s;
		vector<int> v(n,0);
		for(int i=0;i<n;++i){
			v[i]=s[i]-'a';
		}
		int max_num=-1;
		stack<int> st;
		string tmp="";
		string rem="";
		for(int i=n-1;i>=0;--i){
			if(v[i]>=max_num){
				st.push(i);
				max_num=v[i];
				tmp+=s[i];
				s[i]='z';
			}else{
				rem+=s[i];
			}
		}
		reverse(tmp.begin(),tmp.end());
		reverse(rem.begin(),rem.end());
		bool flag=0;
		if(!rem.empty()){
			for(int i=0;i<rem.size()-1;++i){
				// cout<<i<<endl;
				if(rem[i]>rem[i+1]){
					// cout<<i<<" "<<i+1<<endl;
					flag=1;
					break;
				}
			}	
		}
		
		
		if(flag){
			cout<<-1<<"\n";
			continue;
		}
		// cout<<tmp<<endl;
		int ans=0;
		while(!st.empty()){
			if(tmp[0]==tmp[tmp.size()-1]){
				while(!st.empty()){
					int cur_pos=st.top();
					s[cur_pos]=tmp[tmp.size()-1];
					tmp=tmp.substr(0,tmp.size()-1);
					st.pop();
				}
				break;
			}
			int cur_pos=st.top();
			st.pop();
			// cout<<tmp<<endl;
			if(cur_pos!=0){
				if(s[cur_pos+1]<tmp[tmp.size()-1] || s[cur_pos-1]>tmp[tmp.size()-1]){
					flag=1;
					break;
				}
			}else{
				if(s[cur_pos+1]<tmp[tmp.size()-1]){
					flag=1;
					break;
				}
			}
			s[cur_pos]=tmp[tmp.size()-1];
			++ans;
			tmp=tmp.substr(0,tmp.size()-1);
		}
		for(int i=0;i<s.size()-1;++i){
			if(s[i+1]<s[i]){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<-1<<"\n";
		}else{

			cout<<ans<<"\n";
		}
	} 
	return 0;
}