#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define ll long long

ll dy[4]={-1,0,1,0};
ll dx[4]={0,1,0,-1};
ll n,m;
bool isRange(ll y, ll x){
    return (y>=0 && x>=0 && y<n && x<m);
}
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){       
        cin>>n>>m;
        vector<vector<ll>> v;
        
        for(ll i=0;i<n;++i){
            vector<ll> tmp(m,0);
            for(ll j=0;j<m;++j){
                cin>>tmp[j];
            }
            v.push_back(tmp);
        }
        for(ll i=0;i<n;++i){
            for(ll j=0;j<m;++j){
                bool is_big=1;
                for(ll k=0;k<4;++k){
                    ll ny=i+dy[k];
                    ll nx=j+dx[k];
                    if(!isRange(ny,nx)) continue;
                    if(v[i][j]<=v[ny][nx]){
                        is_big=0;
                        break;
                    }
                }
                if(is_big){
                    ll max_num=0;
                    for(ll k=0;k<4;++k){
                        ll ny=i+dy[k];
                        ll nx=j+dx[k];
                        if(!isRange(ny,nx)) continue;
                        max_num=max(max_num,v[ny][nx]);
                    }
                    v[i][j]=max_num;
                }
            }
        }
        for(ll i=0;i<n;++i){
            for(ll j=0;j<m;++j){
                cout<<v[i][j]<<" ";
            }cout<<"\n";
        }
    }
    return 0;
}

