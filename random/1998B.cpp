#include <iostream>
#include <vector>
#include <deque>
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
        for(ll i=0;i<n;++i){
            cin>>v[i];
        }
        vector<ll> ans;
        for(ll i=1;i<n;++i){
            ans.push_back(v[i]);
        }
        ans.push_back(v[0]);
        for(ll i=0;i<n;++i){
            cout<<ans[i]<<" ";
        }cout<<"\n";
    }
    return 0;
}

