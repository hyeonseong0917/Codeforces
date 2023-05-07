#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
 
int GCD(int a, int b){
	if(b==0){
		return a;
	}else{
		return GCD(b,a%b);
	}
}
int t=0;
int N=0;
int input_idx[100000+1];
 
int main() {
	// your code goes here
	cin>>t;
	vector<int> arr;
	vector<int> first_arr, second_arr;
	for(int k=0;k<t;++k){
		arr.clear();
		first_arr.clear();
		second_arr.clear();
		cin>>N;
		for(int i=0;i<N;++i){
			int a=0;
			cin>>a;
			arr.push_back(a);
		}
		if(N==1){
			cout<<0<<endl;
			continue;
		}
		int mid=N/2;
		if(N%2==0){
			for(int i=0;i<N/2;++i){
				first_arr.push_back(arr[i]);
			}	
			for(int i=N/2;i<N;++i){
				second_arr.push_back(arr[i]);
			}
			reverse(second_arr.begin(),second_arr.end());
		}else{
			for(int i=0;i<N/2;++i){
				first_arr.push_back(arr[i]);
			}	
			for(int i=N/2+1;i<N;++i){
				second_arr.push_back(arr[i]);
			}
			reverse(second_arr.begin(),second_arr.end());
		}
		vector<int> diff;
		for(int i=0;i<mid;++i){
			diff.push_back(abs(first_arr[i]-second_arr[i]));
		}
		
		int num=diff[0];
		for(int i=1;i<mid;++i){
			// cout<<num<<" "<<diff[i]<<endl;
			if(num>diff[i]){
				int res=GCD(num,diff[i]);	
				num=res;
			}else{
				int res=GCD(diff[i],num);	
				num=res;
			}
			
			
		}
		
		cout<<num<<endl;
	}
	return 0;
}