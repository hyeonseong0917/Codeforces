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
        ll n;
        cin>>n;
        vector<ll> v(n,0);
        ll cur_max_num=0;
        vector<ll> a;
        for(ll i=0;i<n;++i){
            cin>>v[i];
        }
        ll ans=0;
        for(ll i=0;i<n;++i){
            cur_max_num=max(cur_max_num,v[i]);
            if(cur_max_num>v[i]){
                a.push_back(cur_max_num-v[i]);
            }
        }
        if(a.empty()){
            cout<<0<<"\n";
            continue;
        }
        sort(a.begin(),a.end());
        int as=a.size();
        ans+=(as+1)*a[0];
        for(ll i=1;i<as;++i){
            ans+=(as-i+1)*(a[i]-a[i-1]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}

