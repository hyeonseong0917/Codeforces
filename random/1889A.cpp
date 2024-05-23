#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
using namespace std;

#define ll long long
map<ll,ll> m;
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		if(n==1){
			cout<<-1<<"\n";
			continue;
		}
		int L=0, R=n-1;
		int cnt=0;
		vector<int> ans;
		while(L<=R && cnt<=300){
			// cout<<L<<" "<<R<<endl;
			if(s[L]==s[R]){
				if(s[L]=='1'){
					// 둘 다 1, 무조건 앞에 붙여야 함
					if(L==0){
						string tmp="01";
						tmp+=s;
						s=tmp;
						// cout<<s<<endl;
					}else{
						string tmp=s.substr(0,L)+"01";
						tmp+=s.substr(L,s.size()-L+1);
						s=tmp;
					}
					ans.push_back(L);
					++L;	
					++R;
					++cnt;
				}else{
					// 둘 다 0, 뒤에 붙이기
					if(R==s.size()-1){
						s+="01";
					}else{
						string tmp=s.substr(0,R+1);
						tmp+="01";
						tmp+=s.substr(R+1,s.size()-(R+1)+1);
						s=tmp;	
					}
					ans.push_back(R+1);
					++R;
					++L;
					++cnt;	
				}
				
			}else{
				++L;
				--R;
			}
		}
		if(cnt>300){
			cout<<-1<<"\n";
		}else{
			if(ans.empty()){
				cout<<0<<"\n";
				cout<<"\n";
				continue;
			}
			cout<<ans.size()<<"\n";
			for(int i=0;i<ans.size();++i){
				cout<<ans[i]<<" ";
			}cout<<"\n";
		}
		
	}
	return 0;
}