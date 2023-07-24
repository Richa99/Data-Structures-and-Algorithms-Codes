#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	for(int i=5;i>=1;i--){
		for(int j=1;j<=i;j++){
			cout<<j;
		}
		cout<<endl;
	}
	
	for(int i=1;i<=n;i++){
		for(int k=1;k<=n-i;k++){
			cout<<" ";
		}
		for(int j=1;j<=n;j++){
			cout<<"*";
		}
		cout<<"\n";
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i;j++){
			cout<<" ";
		}
		for(int k=1;k<=i;k++){
			cout<<k<<" ";
		}
		cout<<"\n";

	}
}
