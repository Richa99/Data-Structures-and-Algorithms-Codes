#include<iostream>
#include<vector>
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

int min_diff(vector<int>& nums, int m,int n){
	cout<<"inside function";
	if(n==0 || m==0){
		return 0;
	}
	if(m>n){
		return -1;
	}
	
	sort(nums.begin(),nums.end());
	cout<<" sorted nums "<<endl;
	for(int i=0;i<n;i++){
		cout<<nums[i];
	}
	int min_dif=INT_MAX;
	for (int i=0; (i+m-1) < n ;i++){
		
		int t=nums[i+m-1]-nums[i];
		cout<< "t = "<< t<<endl;
		if(t<min_dif){
			min_dif=t;
		}
		cout<< "min diff = "<< min_dif<<endl;
	}
	return min_dif;
}

int main(){
	vector<int> nums;
	int n,m;
	cout<<"Enter the numbers of packets";
	cin>>n;
	cout<<"Enter the numbers of students";
	cin>>m;
	cout<<"Enter the number of choclates\n";
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		nums.push_back(temp);
	}
	cout<<"minimum diffrence is : "<< min_diff(nums,m,n);
	return 0;
	
}
