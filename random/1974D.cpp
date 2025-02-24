#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;

#define ll long long
ll mod=998244353;
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		// (0,0)에 처음에 둘 다 있음
        // 명령어 집합 s는 n개의 명령어로 주어짐
        // (x,y)
        // N: (x,y+1)
        // S: (x,y-1)
        // E: (x+1,y)
        // W: (x-1,y)
        // 각 device는 최소 1개의 명령어를 실행해야함
        // n개의 instruction 후에 h와 r이 같은 위치에 있도록
        // 불가능하면 -1

        // NENSNE
        // N과 S상쇄, E와 W상쇄
        // 남은 것들 둘 다 짝수여야 가능
        ll n;
        cin>>n;
        string s;
        cin>>s;
        if(n%2==1){
            cout<<"NO"<<"\n";
            continue;
        }
        if(n<4){
            // 1 2 3
            if(n==1){
                cout<<"NO"<<"\n";
            }else if(n==2){
                if(s[0]==s[1]){
                    cout<<"RH"<<"\n";
                }else{
                    cout<<"NO"<<"\n";
                }
            }
            continue;
        }
        ll N=0, S=0, E=0, W=0;
        queue<ll> eq,nq,sq,wq;
        for(ll i=0;i<n;++i){
            if(s[i]=='N'){
                ++N;
                nq.push(i);
            }
            if(s[i]=='S'){
                ++S;
                sq.push(i);
            }
            if(s[i]=='E'){
                ++E;
                eq.push(i);
            }
            if(s[i]=='W'){
                ++W;
                wq.push(i);
            }
        }
        ll nsdiff=abs(N-S);
        ll ewdiff=abs(E-W);
        // N과 S, E와 W 상쇄가능
        if(nsdiff%2==1 || ewdiff%2==1){
            cout<<"NO"<<"\n";
        }else{
            string ans=s;
            ll cnt=0;
            while(!nq.empty() && !sq.empty()){
                ll n_idx=nq.front();
                ll s_idx=sq.front();
                nq.pop();
                sq.pop();
                if(cnt%2==0){
                    s[n_idx]='R';
                    s[s_idx]='R';
                }else{
                    s[n_idx]='H';
                    s[s_idx]='H';
                }
                ++cnt;
            }
            while(!eq.empty() && !wq.empty()){
                ll e_idx=eq.front();
                ll w_idx=wq.front();
                eq.pop();
                wq.pop();
                if(cnt%2==0){
                    s[e_idx]='R';
                    s[w_idx]='R';
                }else{
                    s[e_idx]='H';
                    s[w_idx]='H';
                }
                ++cnt;
            }
            while(!nq.empty()){
                ll n_idx=nq.front();
                nq.pop();
                if(cnt%2==0){
                    s[n_idx]='R';
                }else{
                    s[n_idx]='H';
                }
                ++cnt;
            }
            while(!sq.empty()){
                ll s_idx=sq.front();
                sq.pop();
                if(cnt%2==0){
                    s[s_idx]='R';
                }else{
                    s[s_idx]='H';
                }
                ++cnt;
            }
            while(!eq.empty()){
                ll e_idx=eq.front();
                eq.pop();
                if(cnt%2==0){
                    s[e_idx]='R';
                }else{
                    s[e_idx]='H';
                }
                ++cnt;
            }
            while(!wq.empty()){
                ll w_idx=wq.front();
                wq.pop();
                if(cnt%2==0){
                    s[w_idx]='R';
                }else{
                    s[w_idx]='H';
                }
                ++cnt;
            }
            cout<<s<<"\n";
            
        }
	} 
	return 0;
}