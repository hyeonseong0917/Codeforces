#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long

const int MAX=1000+1;

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	string board[MAX];
	int t=0;
	cin>>t;
	vector<char> edge;
	vector<string> middle;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<MAX;++i){
			board[i]="";
		}
		for(int i=0;i<n;++i){
			cin>>board[i];
		}
		int y=0, x=0;
		int cnt=0;
		while(1){
			edge.clear();
			middle.clear();
			if(y==(n/2)){
				break;
			}
			//edge 확인
			edge.push_back(board[y][x]);
			edge.push_back(board[y][n-x-1]);
			edge.push_back(board[n-y-1][x]);
			edge.push_back(board[n-y-1][n-x-1]);
			sort(edge.begin(),edge.end());
			for(int i=0;i<3;++i){
				if(edge[i]!=edge[3]){
					cnt+=(edge[3]-edge[i]);
				}
			}
			string first_str="", second_str="", third_str="", fourth_str="";
			first_str=board[y].substr(x+1,n-(2*(x+1)));
			third_str=board[n-y-1].substr(x+1,n-(2*(x+1)));
			reverse(third_str.begin(),third_str.end());
			for(int i=y+1;i<n-y-1;++i){
				second_str+=board[i][n-x-1];
				fourth_str+=board[i][x];
			}
			reverse(fourth_str.begin(),fourth_str.end());
			middle.push_back(first_str);
			middle.push_back(second_str);
			middle.push_back(third_str);
			middle.push_back(fourth_str);
			string target="";
			for(int i=0;i<first_str.size();++i){
				char c='a';
				// i번째 자리에 c를 삽입
				for(int j=0;j<middle.size();++j){
					// middle[j]의 i번째 숫자는 무엇인지 비교
					if(c<middle[j][i]){
						c=middle[j][i];
					}
				}
				target+=c;
			}
			for(int i=0;i<middle.size();++i){
				for(int j=0;j<middle[i].size();++j){
					cnt+=(target[j]-middle[i][j]);
				}
			}
			y+=1;
			x+=1;
			// break;
			// cout<<first_str<<" "<<second_str<<" "<<third_str<<" "<<fourth_str<<endl;
			// break;
		}
		cout<<cnt<<"\n";
		
	}	
	return 0;
}