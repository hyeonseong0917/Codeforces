#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}
ll lcm(ll a, ll b){
    ll cur_gcd=gcd(a,b);
    return (a*b)/cur_gcd;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        // a[i]: i번 사탕의 개수
        // b[i]: i번 사탕 1개의 가격
        // 같은 종류의 사탕끼리만 묶을 수 있음
        // 한 묶음: d[i]개의 사탕 
        // 한 묶음의 가격 c[i]=d[i]*b[i]

        ll n;
        cin>>n;
        vector<pair<ll,ll>> v;
        vector<ll> a(n,0), b(n,0);
        for(ll i=0;i<n;++i){
            ll c,d;
            cin>>c>>d;
            a[i]=c;
            b[i]=d;
        }
        // a[i]<=10^9, b[i]<=10^4
        // 20 3 4
        // 6 2 6
        // 14 5 7
        // 20 7 5
        ll ans=1;
        ll cur_gcd=a[0]*b[0];
        ll cur_lcm=b[0];
        for(ll i=1;i<n;++i){
            cur_gcd=gcd(cur_gcd,a[i]*b[i]);
            cur_lcm=lcm(cur_lcm,b[i]);
            if(cur_gcd%cur_lcm!=0){
                ++ans;
                cur_gcd=a[i]*b[i];
                cur_lcm=b[i];
            }
        }
        cout<<ans<<"\n";

    } 
    return 0;
}