#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long


int main() {
    int t;
    cin >> t;
    while(t--){
        // m일동안 진행. i번째 날에는 n
        // i번째 날짜의 우승자는 이후 날짜 참가 못함
        ll m;
        cin>>m;
        vector<ll> v[m+1]; //v[x]: x번째 날에 참가한 참가자들들
        for(ll i=0;i<m;++i){
            ll k;
            cin>>k;
            for(ll j=0;j<k;++j){
                ll a;
                cin>>a;
                v[i].push_back(a);
            }
        }
        map<ll,ll> check;
        vector<ll> ans(m,0);
        bool is_clear=1;
        for(ll i=m-1;i>=0;--i){
            bool flag=0;
            for(ll j=0;j<v[i].size();++j){
                ll c=v[i][j];
                if(!check[c] && !flag){
                    flag=1;
                    ans[i]=c;
                }
                ++check[c];
            }
            if(!flag){
                is_clear=0;
                break;
            }
        }
        if(!is_clear){
            cout<<-1<<"\n";
        }else{
            for(ll i=0;i<m;++i){
                cout<<ans[i]<<" ";
            }cout<<"\n";
        }
    } 
    return 0;
}