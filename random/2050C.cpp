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
        string s;
        cin>>s;
        ll n=s.size();
        if(n==1){
            if(s=="9" || s=="3" || s=="0"){
                cout<<"YES"<<"\n";
            }else{
                cout<<"NO"<<"\n";
            }
        }else{
            
            ll cur_sum=0;
            ll a=0;
            ll b=0;
            for(ll i=0;i<n;++i){
                if(s[i]=='2'){
                    ++a;
                }
                if(s[i]=='3'){
                    ++b;
                }
                cur_sum+=(s[i]-'0');
            }
            
            // cout<<mod;
            // mod를 만들자 2 a개, 3 b개 바탕으로
            bool flag=0;
            for(ll i=0;i<=a;++i){
                for(ll j=0;j<=b;++j){
                    if((cur_sum+2*i+6*j)%9==0){
                        flag=1;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag){
                cout<<"YES"<<"\n";
            }else{
                cout<<"NO"<<"\n";
            }
        }
    }
    return 0;
}

