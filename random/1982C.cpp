#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define ll long long

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n,lv,rv;
        cin>>n>>lv>>rv;
        vector<ll> v(n,0);
        vector<ll> psum(n,0);
        for(ll i=0;i<n;++i){
            cin>>v[i];
        }
        psum[0]=v[0];
        for(ll i=1;i<n;++i){
            psum[i]=psum[i-1]+v[i];
        }
        ll L=0, R=0;
        ll ans=0;
        while(L<=R && R<n){
            // cout<<L<<" "<<R<<endl;
            if(L==R){
                if(v[L]>=lv && v[L]<=rv){
                    ++ans;
                    ++L;
                    ++R;
                }else{
                    if(v[L]>rv){
                        ++L;
                        ++R;
                    }else if(v[L]<lv){
                        ++R;
                    }
                }
            }else{
                ll cur_num=psum[R]-psum[L]+v[L];
                if(cur_num>=lv && cur_num<=rv){
                    // cout<<L<<" "<<R<<" "<<cur_num<<endl;
                    ++ans;
                    L=R+1;
                    R=L;
                }else{
                    if(cur_num>rv){
                        ++L;
                    }else if(cur_num<lv){
                        ++R;
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}

