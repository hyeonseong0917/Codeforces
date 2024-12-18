#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
#define ll long long

bool comp(pair<ll,ll> a, pair<ll,ll> b){
    if(a.first==b.first){
        return a.second>b.second;
    }
    return a.first>b.first;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<pair<ll,ll>> v;
        ll board[2][n];
        ll ans=0;
        ll max_num=-2023101800;
        for(ll i=0;i<2;++i){
            for(ll j=0;j<n;++j){
                cin>>board[i][j];
            }
            
        }
        for(ll i=0;i<n;++i){
            if(board[0][i]>=board[1][i]){
                ans+=board[0][i];
                max_num=max(max_num,board[1][i]);
            }else{
                v.push_back({board[0][i],board[1][i]});
            }
        }
        if(v.empty()){
            ans+=max_num;
        }else{
            ll vs=v.size();
            // n-vs개
            sort(v.begin(),v.end(),comp);
            vector<ll> psum(vs,0),asum(vs,0);
            psum[0]=v[0].second;
            asum[0]=v[0].first;
            for(ll i=1;i<vs;++i){
                psum[i]=psum[i-1]+v[i].second;
                asum[i]=asum[i-1]+v[i].first;
            }
            ll cur_sum=psum[vs-1]+max_num;
            
            for(ll i=0;i<vs;++i){
                cur_sum=max(cur_sum,asum[i]+psum[vs-1]-psum[i]+v[i].second);
            }
            ans+=cur_sum;
        }
        cout<<ans<<"\n";
        
        
    }
    return 0;
}

