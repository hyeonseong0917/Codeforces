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
        string s;
        cin>>s;
        ll n=s.size();
        string tmp=s.substr(0,2);
        if(tmp=="aa" || tmp=="bb" || tmp=="ba"){
            cout<<s[0]<<" "<<s[1]<<" "<<s.substr(2)<<"\n";
        }else{
            ll last_idx=-1;
            for(ll i=2;i<n;++i){
                if(s[i]=='a'){
                    last_idx=i;
                    break;
                }
            }
            if(last_idx==-1){
                cout<<s.substr(0,n-2)<<" "<<s[n-2]<<" "<<s[n-1]<<"\n";
            }else{
                cout<<s[0]<<" "<<s.substr(1,last_idx-1)<<" "<<s.substr(last_idx)<<"\n";
            }
        }
        
    } 
    return 0;
}