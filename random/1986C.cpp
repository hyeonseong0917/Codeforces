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
        ll n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        vector<ll> ind(m,0);
        map<ll,ll> char_cnt;
        for(ll i=0;i<m;++i){
            cin>>ind[i];
            --ind[i];
            ++char_cnt[ind[i]];
        }
        string c;
        cin>>c;
        sort(ind.begin(),ind.end());
        sort(c.begin(),c.end());
        reverse(c.begin(),c.end());
        // cout<<c<<endl;
        ll R=m-1;
        for(ll i=0;i<m;++i){
            if(char_cnt[ind[i]]>=2){
                --char_cnt[ind[i]];
            }else{
                s[ind[i]]=c[R--];
            }
        }
        cout<<s<<"\n";
    }
    return 0;
}

