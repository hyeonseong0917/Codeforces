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
    while (t--) {
        ll n;
        cin>>n;
        vector<ll> a(n,0), b(n,0);
        for(ll i=0;i<n;++i){
            cin>>a[i];
        }
        for(ll i=0;i<n;++i){
            cin>>b[i];
        }
        bool flag=0;
        for(ll i=0;i<n;++i){
            if(a[i]<b[i]){
                ll tmp=a[i];
                a[i]=b[i];
                b[i]=tmp;
            }
        }
        for(ll i=0;i<n-1;++i){
            if(a[i]>a[n-1] || b[i]>b[n-1]){
                flag=1;
                break;
            }
        }
        if(flag){
            cout<<"NO"<<"\n";
        }else{
            cout<<"YES"<<"\n";
        }
    } 
    return 0;
}