#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long
ll mod=998244353;
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		// s
        // 새로운 string r을 구성 => s의 고유한 문자들을 사전순으로
        // encoding된 string이 주어질 때 decoding된 스트링 구하기
        ll n;
        cin>>n;
        string s;
        cin>>s;
        // serofedsoc
        // 1. disctinct string: serofdc
        // 2. sort: cdefors
        // 3. s->c, c->s
        vector<ll> check(26+1,0);
        for(ll i=0;i<n;++i){
            ++check[s[i]-'a'];
        }
        string r="";
        for(ll i=0;i<26;++i){
            if(check[i]){
                r+=('a'+i);
            }
        }
        // cout<<r<<endl;
        map<char,char> m;
        ll L=0, R=r.size()-1;
        while(L<=R){
            if(L==R){
                m[r[L]]=r[L];
                break;
            }
            m[r[L]]=r[R];
            m[r[R]]=r[L];
            ++L;
            --R;
        }
        // cout<<s<<endl;
        for(ll i=0;i<n;++i){
            s[i]=m[s[i]];
            // cout<<m[s[i]]<<endl;
        }
        cout<<s<<"\n";
	} 
	return 0;
}