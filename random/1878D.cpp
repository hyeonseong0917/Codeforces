#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long
ll mod=998244353;
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
        // 길이 n인 문자열
        // 양의 정수 k와 배열 l,r이 주어짐
        // l[1]=1, r[k]=n
        // l[i]<=r[i], 1<=i<=k
        // l[i]=r[i-1]+1, 2<=i<=k

        // q가 주어진다. s에 해야하는 수정사항을 나타내는
        // 각 수정사항은 정수 x로 이루어짐
        // l[i]<=x<=r[i]인 유니크한 i를 찾는다
        // a=min(x,r[i]+l[i]-x), b=max(x,r[i]+l[i]-x)
        // 인덱스 a에서 인덱스 b까지 reverse한다
        // 모든 modification이 끝난 후 문자열
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<ll> a(k,0), b(k,0);
        for(ll i=0;i<k;++i){
            cin>>a[i];
            --a[i];
        }
        for(ll i=0;i<k;++i){
            cin>>b[i];
            --b[i];
        }
        ll q;
        cin>>q;
        vector<ll> cnt(n+1,0);
        for(ll i=0;i<q;++i){
            ll a;
            cin>>a;
            ++cnt[a-1];
        }
        string ans="";
        for(ll i=0;i<k;++i){
            string tmp=s.substr(a[i],b[i]-a[i]+1);
            ll L=a[i];
            ll R=b[i];
            ll sum=0;
            for(ll j=L;j<=(L+R)/2;++j){
                sum+=cnt[j]+cnt[R-j+L];
                if(sum%2==1){
                    char c=tmp[j-L];
                    tmp[j-L]=tmp[R-j];
                    tmp[R-j]=c;
                }
            }
            ans+=tmp;
        }
        cout<<ans<<"\n";
	} 
	return 0;
}