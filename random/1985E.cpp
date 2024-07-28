#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
#define ll long long

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll x,y,z,k;
        cin>>x>>y>>z>>k;
        vector<ll> v;
        v.push_back(x);
        v.push_back(y);
        v.push_back(z);
        vector<ll> c;
        for(ll i=1;i<=sqrt(k);++i){
            if(k%i==0){
                c.push_back(i);
                if(i!=k/i){
                    c.push_back(k/i);
                }    
            }
        }
        sort(c.begin(),c.end());
        reverse(c.begin(),c.end());
        ll cs=c.size();
        // cout<<cs<<endl;
        // for(ll i=0;i<cs;++i){
        //     cout<<c[i]<<" ";
        // }
        // break;
        ll ans=0;
        for(ll i=0;i<3;++i){
            for(ll j=0;j<3;++j){
                for(ll m=0;m<3;++m){
                    if(i!=j && i!=m && j!=m){
                        for(ll p=0;p<cs;++p){
                            for(ll q=cs-1;q>=0;--q){
                                if(k%(c[p]*c[q])==0){
                                    ll fst_num=v[i]-c[p];
                                    ll sed_num=v[j]-c[q];
                                    ll trd_num=v[m]-k/(c[p]*c[q]);
                                    if(fst_num>=0 && sed_num>=0 && trd_num>=0){
                                        ++fst_num;
                                        ++sed_num;
                                        ++trd_num;
                                        ans=max(ans,fst_num*sed_num*trd_num);
                                    }
                                    // c[p]
                                    // c[q]
                                    // k/(c[p]*c[q]);    
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}

