#include<iostream>
#include<stdio.h>

using namespace std;

int Delete(int a[],int n,int index){
	for(int i=index;i<n;i++){
		a[i]=a[i+1];
	}
	n=n-1;
	return n;
}

int main(){
	int arr[]={1,2,3,4,5,6}; int res[6]={0},num,r_size;
	num=sizeof(arr)/sizeof(int);
	cout<<"arr size: "<<num<<endl;
	for(int k=0;k<num;k++){
		res[k]=arr[k];
	}
	
	for(int i=0;i<6;i++){
		if (i%2==0){
			//cout<<"updated num"<<num<<endl;
			cout<<"i location" << i << endl;
			num=Delete(res,num,i);
			cout<<"Deleted array"<<endl;
			for (int j=0;j<num;j++){
				cout<<res[j]<<endl;
			
			}
			
			for (int j=0;j<num;j++){
				cout<<"updated array : "<<arr[j];
				res[j]=res[j];
				cout<< "Element added : "<< res[j]<<endl;
			
			}
		}
			
	}
	cout<<"final result";
	for(int l=0;l<num;l++){
		cout<<res[l]<<endl;
	}
}
