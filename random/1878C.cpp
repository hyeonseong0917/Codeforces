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
		// n,k,x
        // k개의 고유한 정수를 1에서 n사이의 정수 중에서 골라야함
        // 그들의 합이 x와 같아야함
        ll n,k,x;
        cin>>n>>k>>x;
        // 1에서 n까지 k개를 골라서 그들의 합을 x로 만들 수 있으면
        // 5 3 10
        // 6 5 20
        // 1에서 6까지 5개를 골라서 합을 20?
        // 언제 안될까?
        // [n-k+1,n]의 합이 x보다 작다면
        // [1,k]의 합이 x보다 크다면
        ll fst_sum=0;
        // for(ll i=n-k+1;i<=n;++i){
        //     fst_sum+=i;
        // }
        fst_sum=((n+1)*n)/2-((n-k+2)*(n-k+1))/2+(n-k+1);
        ll sed_sum=((k+1)*k)/2;
        if(fst_sum<x || sed_sum>x){
            cout<<"NO"<<"\n";
            continue;
        }
        cout<<"YES"<<"\n";
        // ll cur_sum=sed_sum; // 1에서 k까지의 합
        // ll last_num=k;
        // ll cnt=0;
        // while(cnt<n){
        //     if(cur_sum==x){
        //         break;
        //     }
        //     ll L=last_num, R=n-cnt;
        //     ll max_num=L;
        //     while(L<=R){
        //         ll mid=(L+R)/2;
        //         if(cur_sum-last_num+mid<=x){
        //             max_num=max(max_num,mid);
        //             L=mid+1;
        //         }else{
        //             R=mid-1;
        //         }
        //     }
        //     cur_sum-=last_num;
        //     cur_sum+=max_num;
        //     ++cnt;
        //     --last_num;
        // }
        // if(cur_sum==x){
        //     cout<<"YES"<<"\n";
        // }else{
        //     cout<<"NO"<<"\n";
        // }
	} 
	return 0;
}