#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long

string to_bin(ll a){
	string s="";
	while(a){
		s+=(a%2)+'0';
		a/=2;
	}
	reverse(s.begin(),s.end());
	return s;
}
string xor_calc(string a, string b){
	string s="";
	int N=a.size();
	for(int i=0;i<N;++i){
		if(a[i]==b[i]){
			s+='0';
		}else{
			s+='1';
		}
	}
	return s;
}
ll bin_to_ll(string s){
	ll ans=0;
	reverse(s.begin(),s.end());
	for(ll i=0;i<s.size();++i){
		if(s[i]=='1'){
			ans+=(ll)pow(2,i);
		}
	}
	return ans;
}
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		ll a,b,r;
		cin>>a>>b>>r;
		ll tmp=0;
		if(a<b){
			tmp=a;
			a=b;
			b=tmp;
		}
		string A=to_bin(a);
		string B=to_bin(b);
		if(A.size()>B.size()){
			int diff=A.size()-B.size();
			reverse(B.begin(),B.end());
			for(int i=0;i<diff;++i){
				B+='0';
			}
			reverse(B.begin(),B.end());
		}
		int N=A.size();
		int cnt=0;
		ll init_r=r;
		while(r){
			r/=2;
			++cnt;
		}
		r=init_r;
		// --cnt;
		// cout<<cnt<<"\n";
		bool flag=0;
		string ans="";
		if(N-cnt<0){
			reverse(A.begin(),A.end());
			for(int i=0;i<N-cnt;++i){
				A+='0';
			}
			reverse(A.begin(),A.end());
			reverse(B.begin(),B.end());
			for(int i=0;i<N-cnt;++i){
				B+='0';
			}
			reverse(B.begin(),B.end());
			N=cnt;
		}
		for(int i=0;i<N-cnt;++i){
			ans+='0';
			if(A[i]=='1' && B[i]=='0'){
				flag=1;
			}
		}
		ll cur_num=0;
		for(int i=N-cnt;i<N;++i){
			if(A[i]==B[i]){
				ans+='0';
			}else{
				if(A[i]=='1' && B[i]=='0'){
					if(flag){
						if(cur_num+(ll)pow(2,N-i-1)<=r){
							cur_num+=(ll)pow(2,N-i-1);
							ans+='1';
						}else{
							ans+='0';
						}
						
					}else{
						flag=1;
						ans+='0';
					}
				}else{
					ans+='0';
				}
			}
		}
		string A_ans=xor_calc(A,ans);
		string B_ans=xor_calc(B,ans);
		ll A_ll=bin_to_ll(A_ans);
		ll B_ll=bin_to_ll(B_ans);
		// cout<<A<<"\n";
		// cout<<B<<"\n";
		// cout<<ans<<"\n";
		// cout<<A_ll<<"\n";
		// cout<<B_ll<<"\n";
		cout<<A_ll-B_ll<<"\n";



	}	
	return 0;
}