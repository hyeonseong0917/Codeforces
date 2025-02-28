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
        bool flag=0;
        string a,b,c;
        for(ll i=0;i<n;++i){
            for(ll j=i+1;j<n-1;++j){
                // [0,i]
                // [i+1,j]
                // [j+1,n-1]
                string fst_str=s.substr(0,i+1);
                string sed_str=s.substr(i+1,j-(i+1)+1);
                string trd_str=s.substr(j+1);
                if(fst_str<=sed_str && trd_str<=sed_str){
                    a=fst_str;
                    b=sed_str;
                    c=trd_str;
                    flag=1;
                    break;
                }
                if(fst_str>=sed_str && trd_str>=sed_str){
                    a=fst_str;
                    b=sed_str;
                    c=trd_str;
                    flag=1;
                    break;
                }
            }
        }
        if(flag){
            cout<<a<<" "<<b<<" "<<c<<"\n";
        }else{
            cout<<":("<<"\n";
        }
    } 
    return 0;
}