#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o;
	cin>>o;
	while(o--){
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		ll ans=0;
		ll fst_num=0;
		ll sed_num=0;
		if(a>c){
			++fst_num;
		}else if(a<c){
			++sed_num;
		}
		if(b>d){
			++fst_num;
		}else if(b<d){
			++sed_num;
		}
		if(fst_num>sed_num){
			++ans;
		}
		fst_num=0;
		sed_num=0;
		if(a>d){
			++fst_num;
		}else if(a<d){
			++sed_num;
		}
		if(b>c){
			++fst_num;
		}else if(b<c){
			++sed_num;
		}
		if(fst_num>sed_num){
			++ans;
		}
		fst_num=0;
		sed_num=0;
		if(b>d){
			++fst_num;
		}else if(b<d){
			++sed_num;
		}
		if(a>c){
			++fst_num;
		}else if(a<c){
			++sed_num;
		}
		if(fst_num>sed_num){
			++ans;
		}
		fst_num=0;
		sed_num=0;
		if(b>c){
			++fst_num;
		}else if(b<c){
			++sed_num;
		}
		if(a>d){
			++fst_num;
		}else if(a<d){
			++sed_num;
		}
		if(fst_num>sed_num){
			++ans;
		}
		cout<<ans<<"\n";

	}
	return 0;
}