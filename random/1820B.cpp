#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		// s: 길이 n 바이너리 스트링
		// n*n테이블을 만들것임. 0과 1로 이루어진
		// 처음 row에는 s를 씀
		// 두번째 row에는 사이클릭 시프트 1버
		// 세번째 row에는 사이클릭 시프트 2번
		// k번째 row(0-based)는 k번 사이클릭 시프트 수행

		// 011110
		// 111100
		// 111001
		// 110011
		// 100111
		// 001111

		// 최대 사각형의 넓이??
		// 0111110
		// 1111100
		// 1111001
		// 1110011
		// 1100111
		string s;
		cin>>s;
		ll n=s.size();
		bool is_zero=0;
		ll max_num=0;
		ll cnt=0;
		for(ll i=0;i<n;++i){
			if(s[i]=='0'){
				is_zero=1;
				max_num=max(max_num,cnt);
				cnt=0;
			}else{
				++cnt;
			}
		}
		// 101
		// 011
		// 110
		if(!is_zero){
			cout<<n*n<<"\n";
			continue;
		}
		max_num=max(max_num,cnt);
		// 양쪽 끝?
		ll fst_cnt=0;
		for(ll i=0;i<n;++i){
			if(s[i]=='0') break;
			++fst_cnt;
		}
		for(ll i=n-1;i>=0;--i){
			if(s[i]=='0') break;
			++fst_cnt;
		}
		max_num=max(max_num,fst_cnt);
		ll c=1;
		ll ans=0;
		while(max_num){
			ans=max(ans,max_num*c);
			--max_num;
			++c;
		}
		cout<<ans<<"\n";
	}
	return 0;
}