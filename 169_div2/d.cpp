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
		ll n,q;
		cin>>n>>q;
		vector<string> v;
		for(ll i=0;i<n;++i){
			string s;
			cin>>s;
			sort(s.begin(),s.end());
			v.push_back(s);
		}
		vector<ll> br_dp(n,-1), bg_dp(n,-1), by_dp(n,-1), rg_dp(n,-1),ry_dp(n,-1),gy_dp(n,-1);
		if(v[n-1]=="BR"){
			br_dp[n-1]=n-1;
		}else if(v[n-1]=="BG"){
			bg_dp[n-1]=n-1;
		}else if(v[n-1]=="BY"){
			by_dp[n-1]=n-1;
		}else if(v[n-1]=="GR"){
			rg_dp[n-1]=n-1;
		}else if(v[n-1]=="RY"){
			ry_dp[n-1]=n-1;
		}else if(v[n-1]=="GY"){
			gy_dp[n-1]=n-1;
		}
		for(ll i=n-2;i>=0;--i){
			if(v[i]=="BR"){
				br_dp[i]=i;
				bg_dp[i]=bg_dp[i+1];
				by_dp[i]=by_dp[i+1];
				rg_dp[i]=rg_dp[i+1];
				ry_dp[i]=ry_dp[i+1];
				gy_dp[i]=gy_dp[i+1];
			}else if(v[i]=="BG"){
				bg_dp[i]=i;
				br_dp[i]=br_dp[i+1];
				by_dp[i]=by_dp[i+1];
				rg_dp[i]=rg_dp[i+1];
				ry_dp[i]=ry_dp[i+1];
				gy_dp[i]=gy_dp[i+1];
			}else if(v[i]=="BY"){
				by_dp[i]=i;
				br_dp[i]=br_dp[i+1];
				by_dp[i]=by_dp[i+1];
				rg_dp[i]=rg_dp[i+1];
				ry_dp[i]=ry_dp[i+1];
				gy_dp[i]=gy_dp[i+1];
			}else if(v[i]=="GR"){
				rg_dp[i]=i;
				bg_dp[i]=bg_dp[i+1];
				by_dp[i]=by_dp[i+1];
				br_dp[i]=br_dp[i+1];
				ry_dp[i]=ry_dp[i+1];
				gy_dp[i]=gy_dp[i+1];
			}else if(v[i]=="RY"){
				ry_dp[i]=i;
				bg_dp[i]=bg_dp[i+1];
				by_dp[i]=by_dp[i+1];
				rg_dp[i]=rg_dp[i+1];
				br_dp[i]=br_dp[i+1];
				gy_dp[i]=gy_dp[i+1];
			}else if(v[i]=="GY"){
				gy_dp[i]=i;
				bg_dp[i]=bg_dp[i+1];
				by_dp[i]=by_dp[i+1];
				rg_dp[i]=rg_dp[i+1];
				ry_dp[i]=ry_dp[i+1];
				br_dp[i]=br_dp[i+1];
			}	
		}
		
		// for(ll i=0;i<n;++i){
		// 	cout<<rg_dp[i]<<" ";
		// }
		for(ll i=0;i<q;++i){
			ll a,b;
			cin>>a>>b;
			--a;
			--b;
			ll tmp_a=min(a,b);
			ll tmp_b=max(a,b);
			a=tmp_a;
			b=tmp_b;
			string s=v[a];
			string t=v[b];	
			ll cnt=0;
			for(ll j=0;j<2;++j){
				for(ll k=0;k<2;++k){
					if(s[j]==t[k]){
						++cnt;
					}
				}
			}
			if(cnt>=1){
				cout<<b-a<<"\n";
			}else{
				// 하나도 안겹침
				// a이후 인덱스에서 s의 문자 하나 + t의 문자 하나 조합이 있는지?
				// 해당 조합이 있다면 가장 최근의 해당 인덱스는?
				ll ans=1222232421;
				string fst_str="", sed_str="", trd_str="", fth_str="";
	
				fst_str+=s[0];
				fst_str+=t[0];
				sort(fst_str.begin(),fst_str.end());
				if(fst_str=="BG"){
					if(bg_dp[a]!=-1){
						if(bg_dp[a]<b){
							ans=min(ans,b-a);
						}else{
							ans=min(ans,bg_dp[a]-a+abs(bg_dp[a]-b));
						}
						
					}
				}else if(fst_str=="BR"){
					if(br_dp[a]!=-1){
						if(br_dp[a]<b){
							ans=min(ans,b-a);
						}else{
							ans=min(ans,br_dp[a]-a+abs(br_dp[a]-b));
						}
						// ans=min(ans,br_dp[a]+abs(br_dp[a]-b));
					}
				}else if(fst_str=="BY"){
					if(by_dp[a]!=-1){
						if(by_dp[a]<b){
							ans=min(ans,b-a);
						}else{
							ans=min(ans,by_dp[a]-a+abs(by_dp[a]-b));
						}
						// ans=min(ans,by_dp[a]+abs(by_dp[a]-b));
					}
				}else if(fst_str=="GR"){
					if(rg_dp[a]!=-1){
						if(rg_dp[a]<b){
							ans=min(ans,b-a);
						}else{
							ans=min(ans,rg_dp[a]-a+abs(rg_dp[a]-b));
						}
						// ans=min(ans,rg_dp[a]+abs(rg_dp[a]-b));
					}
				}else if(fst_str=="GY"){
					if(gy_dp[a]!=-1){
						if(gy_dp[a]<b){
							ans=min(ans,b-a);
						}else{
							ans=min(ans,gy_dp[a]-a+abs(gy_dp[a]-b));
						}
						// ans=min(ans,gy_dp[a]+abs(gy_dp[a]-b));
					}
				}else if(fst_str=="RY"){
					if(ry_dp[a]!=-1){
						if(ry_dp[a]<b){
							ans=min(ans,b-a);
						}else{
							ans=min(ans,ry_dp[a]-a+abs(ry_dp[a]-b));
						}
						// ans=min(ans,ry_dp[a]+abs(ry_dp[a]-b));
					}
				}
				sed_str+=s[0];
				sed_str+=t[1];
				sort(sed_str.begin(),sed_str.end());
				if(sed_str=="BG"){
					if(bg_dp[a]!=-1){
						if(bg_dp[a]<b){
							ans=min(ans,b-a);
						}else{
							ans=min(ans,bg_dp[a]-a+abs(bg_dp[a]-b));
						}
						// ans=min(ans,bg_dp[a]+abs(bg_dp[a]-b));
					}
				}else if(sed_str=="BR"){
					if(br_dp[a]!=-1){
						if(br_dp[a]<b){
							ans=min(ans,b-a);
						}else{
							ans=min(ans,br_dp[a]-a+abs(br_dp[a]-b));
						}
						// ans=min(ans,br_dp[a]+abs(br_dp[a]-b));
					}
				}else if(sed_str=="BY"){
					if(by_dp[a]!=-1){
						// ans=min(ans,by_dp[a]+abs(by_dp[a]-b));
						if(by_dp[a]<b){
							ans=min(ans,b-a);
						}else{
							ans=min(ans,by_dp[a]-a+abs(by_dp[a]-b));
						}
					}
				}else if(sed_str=="GR"){
					if(rg_dp[a]!=-1){
						// ans=min(ans,rg_dp[a]+abs(rg_dp[a]-b));
						if(rg_dp[a]<b){
							ans=min(ans,b-a);
						}else{
							ans=min(ans,rg_dp[a]-a+abs(rg_dp[a]-b));
						}
					}
				}else if(sed_str=="GY"){
					if(gy_dp[a]!=-1){
						// ans=min(ans,gy_dp[a]+abs(gy_dp[a]-b));
						if(gy_dp[a]<b){
							ans=min(ans,b-a);
						}else{
							ans=min(ans,gy_dp[a]-a+abs(gy_dp[a]-b));
						}
					}
				}else if(sed_str=="RY"){
					if(ry_dp[a]!=-1){
						// ans=min(ans,ry_dp[a]+abs(ry_dp[a]-b));
						if(ry_dp[a]<b){
							ans=min(ans,b-a);
						}else{
							ans=min(ans,ry_dp[a]-a+abs(ry_dp[a]-b));
						}
					}
				}
				trd_str+=s[1];
				trd_str+=t[0];
				sort(trd_str.begin(),trd_str.end());
				if(trd_str=="BG"){
					if(bg_dp[a]!=-1){
						// ans=min(ans,bg_dp[a]+abs(bg_dp[a]-b));
						if(bg_dp[a]<b){
							ans=min(ans,b-a);
						}else{
							ans=min(ans,bg_dp[a]-a+abs(bg_dp[a]-b));
						}
					}
				}else if(trd_str=="BR"){
					if(br_dp[a]!=-1){
						// ans=min(ans,br_dp[a]+abs(br_dp[a]-b));
						if(br_dp[a]<b){
							ans=min(ans,b-a);
						}else{
							ans=min(ans,br_dp[a]-a+abs(br_dp[a]-b));
						}
					}
				}else if(trd_str=="BY"){
					if(by_dp[a]!=-1){
						// ans=min(ans,by_dp[a]+abs(by_dp[a]-b));
						if(by_dp[a]<b){
							ans=min(ans,b-a);
						}else{
							ans=min(ans,by_dp[a]-a+abs(by_dp[a]-b));
						}
					}
				}else if(trd_str=="GR"){
					if(rg_dp[a]!=-1){
						// ans=min(ans,rg_dp[a]+abs(rg_dp[a]-b));
						if(rg_dp[a]<b){
							ans=min(ans,b-a);
						}else{
							ans=min(ans,rg_dp[a]-a+abs(rg_dp[a]-b));
						}
					}
				}else if(trd_str=="GY"){
					if(gy_dp[a]!=-1){
						// ans=min(ans,gy_dp[a]+abs(gy_dp[a]-b));
						if(gy_dp[a]<b){
							ans=min(ans,b-a);
						}else{
							ans=min(ans,gy_dp[a]-a+abs(gy_dp[a]-b));
						}
					}
				}else if(trd_str=="RY"){
					if(ry_dp[a]!=-1){
						// ans=min(ans,ry_dp[a]+abs(ry_dp[a]-b));
						if(ry_dp[a]<b){
							ans=min(ans,b-a);
						}else{
							ans=min(ans,ry_dp[a]-a+abs(ry_dp[a]-b));
						}
					}
				}
				fth_str+=s[1];
				fth_str+=t[1];
				sort(fth_str.begin(),fth_str.end());
				if(fth_str=="BG"){
					if(bg_dp[a]!=-1){
						// ans=min(ans,bg_dp[a]+abs(bg_dp[a]-b));
						if(bg_dp[a]<b){
							ans=min(ans,b-a);
						}else{
							ans=min(ans,bg_dp[a]-a+abs(bg_dp[a]-b));
						}
					}
				}else if(fth_str=="BR"){
					if(br_dp[a]!=-1){
						// ans=min(ans,br_dp[a]+abs(br_dp[a]-b));
						if(br_dp[a]<b){
							ans=min(ans,b-a);
						}else{
							ans=min(ans,br_dp[a]-a+abs(br_dp[a]-b));
						}
					}
				}else if(fth_str=="BY"){
					if(by_dp[a]!=-1){
						// ans=min(ans,by_dp[a]+abs(by_dp[a]-b));
						if(by_dp[a]<b){
							ans=min(ans,b-a);
						}else{
							ans=min(ans,by_dp[a]-a+abs(by_dp[a]-b));
						}
					}
				}else if(fth_str=="GR"){
					if(rg_dp[a]!=-1){
						// ans=min(ans,rg_dp[a]+abs(rg_dp[a]-b));
						if(rg_dp[a]<b){
							ans=min(ans,b-a);
						}else{
							ans=min(ans,rg_dp[a]-a+abs(rg_dp[a]-b));
						}
					}
				}else if(fth_str=="GY"){
					if(gy_dp[a]!=-1){
						// ans=min(ans,gy_dp[a]+abs(gy_dp[a]-b));
						if(gy_dp[a]<b){
							ans=min(ans,b-a);
						}else{
							ans=min(ans,gy_dp[a]-a+abs(gy_dp[a]-b));
						}
					}
				}else if(fth_str=="RY"){
					if(ry_dp[a]!=-1){
						// ans=min(ans,ry_dp[a]+abs(ry_dp[a]-b));
						if(ry_dp[a]<b){
							ans=min(ans,b-a);
						}else{
							ans=min(ans,ry_ dp[a]-a+abs(ry_dp[a]-b));
						}
					}
				}
				// cout<<fst_str<<" "<<sed_str<<" "<<trd_str<<" "<<fth_str<<endl;
				// cout<<rg_dp[a]<<endl;
				if(ans==1222232421){
					cout<<-1<<"\n";
				}else{
					cout<<ans<<"\n";
				}
				
			}
		}
	}
	return 0;
}