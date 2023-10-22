#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;

	// 3개의 threadlet과 가위 쌍
	// 하나의 threadlet을 두개의 threadlet으로 나눈다
	// 최대 3번까지 나눌 수 있을때, 동일한 길이로 나눌 수 있는지?
	while(t--){
		vector<ll> v;
		for(int i=0;i<3;++i){
			ll a=0;
			cin>>a;
			v.push_back(a);
		}
		if(v[0]==v[1] && v[1]==v[2]){
			cout<<"YES"<<"\n";
			continue;
		}
		sort(v.begin(),v.end());
		int cnt=3;
		bool flag=0;
		while(cnt--){
			ll max_num=v[v.size()-1];
			if(max_num>v[0]){
				v[v.size()-1]=max_num-v[0];
				v.push_back(v[0]);
			}
			sort(v.begin(),v.end());
			flag=1;
			for(int i=1;i<v.size();++i){
				if(v[i]!=v[i-1]){
					flag=0;
					break;
				}
			}
			if(flag){
				break;
			}
		}
		if(flag){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
	}	
	return 0;
}