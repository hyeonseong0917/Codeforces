#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

ll dy[4]={-1,0,1,0};
ll dx[4]={0,-1,0,1};
ll n,m;
bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<n && x<m);
}
ll board[300+1][300+1];
int main() {
	// your code goes here
	int o=1;
	cin>>o;
	while(o--){
		// 1608
		// n*m의 그리드
		// 각 셀은 0 혹은 양수
		// 언제 good이라고 부르는지?
		// k>0이 쓰여있고 k개의 인접한 셀들이
		// 0보다 큰 것이 쓰여 있다며
		// 어떤 한 셀을 선택해 1을 증가시킬 수 있다.
		// 원하는 만큼 해도 됨. 격자를 좋게 만들 수 있는지
		cin>>n>>m;
		
		bool flag=0;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				cin>>board[i][j];
				if(board[i][j]>4){
					flag=1;
				}
			}

		}
		if(flag){
			cout<<"NO"<<"\n";
			continue;
		}
		
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				// cout<<i<<" "<<j<<endl;
				if(board[i][j]){
					// cout<<i<<" "<<j<<endl;
					ll cnt=0; // 인접한 양수의 개수
					for(ll k=0;k<4;++k){
						ll ny=i+dy[k];
						ll nx=j+dx[k];
						if(!isRange(ny,nx)) continue;
						if(board[ny][nx]){
							++cnt;
						}
					}
					if(cnt<board[i][j]){
						ll empty_cnt=0;
						for(ll k=0;k<4;++k){
							ll ny=i+dy[k];
							ll nx=j+dx[k];
							if(!isRange(ny,nx)) continue;
							if(!board[ny][nx]){
								++empty_cnt;
							}
						}
						// cout<<cnt<<" "<<empty_cnt<<endl;
						if(empty_cnt<board[i][j]-cnt){
							flag=1;
							break;
						}else{
							ll diff=board[i][j]-cnt;
							// cout<<diff<<endl;
							for(ll k=0;k<4;++k){
								ll ny=i+dy[k];
								ll nx=j+dx[k];
								if(!isRange(ny,nx)) continue;
								if(!board[ny][nx] && diff){
									// cout<<ny<<" "<<nx<<endl;
									--diff;
									board[ny][nx]=1;
								}
							}	
						}
					}else{
						// cnt>=board[i][j]
						board[i][j]=cnt;
					}
				}
			}
		}
		if(flag){
			cout<<"NO"<<"\n";
			continue;
		}
		cout<<"YES"<<"\n";
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				// cout<<board[i][j]<<" ";
				if(board[i][j]){
					ll cnt=0;
					for(ll k=0;k<4;++k){
						ll ny=i+dy[k];
						ll nx=j+dx[k];
						if(!isRange(ny,nx)) continue;
						if(board[ny][nx]){
							++cnt;
						}
					}
					if(cnt>=board[i][j]){
						board[i][j]=cnt;
					}
				}
			}
		}
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				cout<<board[i][j]<<" ";
			}cout<<"\n";
		}

	} 

	return 0;
}