#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int o=1;
	// cin>>o;
	while(o--){
		// n개의 램프들로 이루어진
		// 각 램프들은 r,g,b로 이루어짐
		// i번째 램프의 색은 s[i]임
		// 같은 색의 램프 간 거리가 3의 배수가 되도록
		// 램프들을 다시 칠해야함
		// 다시 칠해야 하는 램프들의 최소 개수와 이 때의 답을 출력
		ll n;
		cin>>n;
		string s;
		cin>>s;
		// 0123456
		// RGBGRBB
		// 처음 패턴 RGBRGBRGB
		// 가능한 최종 패턴들
		// RGBRGBRGB
		// RBGRBGRBG
		// BGRBGR
		// BRGBRG
		// GBRGBR
		// GRBGRB
		vector<string> v;
		string a="",b="",c="",d="",e="",f="";
		for(ll i=0;i<n;++i){
			if(i%3==0){
				a+='R';
				b+='R';
				c+='B';
				d+='B';
				e+='G';
				f+='G';
			}else if(i%3==1){
				a+='G';
				b+='B';
				c+='G';
				d+='R';
				e+='B';
				f+='R';
			}else{
				a+='B';
				b+='G';
				c+='R';
				d+='G';
				e+='R';
				f+='B';
			}
		}
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		v.push_back(d);
		v.push_back(e);
		v.push_back(f);
		ll ans=2023101800;
		string k="";
		for(ll i=0;i<6;++i)	{
			ll cnt=0;
			for(ll j=0;j<n;++j){
				if(v[i][j]!=s[j]){
					++cnt;
				}
			}
			if(cnt<ans){
				ans=cnt;
				k=v[i];
			}
		}
		cout<<ans<<"\n";
		cout<<k<<"\n";
		
	} 

	return 0;
}