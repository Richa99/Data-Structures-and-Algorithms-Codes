#include<iostream>
#include<stdio.h>
using namespace std;

int insert(int a[],int n, int ele,int index){
	int j=n-1;
	while(j>=index){
		a[j+1]=a[j];
		j--;
	}
	a[index]=ele;
	n=n+1;
	return n;
}

int Delete(int a[],int n,int index){
	for(int j=index;j<n;j++){
		a[j]=a[j+1];
	}
	n=n-1;
	return n;
}

int main(){
	int a1[100],c[100]; 
	int n,ele, index,size,updated_size;
	cout<<"Enter the number of elements "<<endl;
	cin>>n;
	cout<<"Enter the elements of the array"<<endl;
	for (int i=0;i<n;i++){
		cin>>a1[i];
	}
	cout<<"The array is : "<<endl;
	for (int i=0;i<n;i++){
		cout<<a1[i]<<endl;
	}
	
	
//Deletion
	int del_index;
	cout<<"Enter the deletion index"<<endl;
	cin>>del_index;
	int after_del=Delete(a1,n,del_index);
	
	cout<<"The array is : "<<endl;
	for (int i=0;i<after_del;i++){
		cout<<a1[i]<<endl;
	}
	
	
	
	
//	cout<<"Enter the element to be entered "<<endl;
//	cin>>ele;
//	for (int i=0;i<n;i++){
//		if(a1[i]==ele+1){
//			index=i;
//			updated_size=insert(a1,n,ele,index);
//			cout<<"The array is : "<<endl;
//			for (int i=0;i<updated_size;i++){
//				cout<<a1[i]<<endl;
//			}
//		}
//	}




//Merging two arrays
	int b1[5]={2,3,4,5,6};
	cout<<"The array b1 is : "<<endl;
	for (int i=0;i<5;i++){
		cout<<b1[i]<<endl;
	}
	int j,k,c_size;
	//Merging
	for(j=0;j<n;j++){
		c[j]=a1[j];
	}
	
	for(k=0;k<5;k++){
		c[j]=b1[k];
		j++;
	}
	
	//c_size=sizeof(c)/sizeof(int);
	cout<<"The array c is : "<<endl;
	for (int i=0;i<n+5;i++){
		cout<<c[i]<<endl;
	}
	
	
	
	
}
