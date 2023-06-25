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

int main(){
	int a1[100]; 
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
	
//	size=sizeof(a1)/sizeof(int);
	
	cout<<"Enter the element to be inserted : "<<endl;
	cin>>ele;
	cout<<"Enter the index : "<<endl;
	cin>>index;
	
	//Inserting at a specific position
	updated_size=insert(a1,n,ele,index);
	cout<<"The array is : "<<endl;
	for (int i=0;i<updated_size;i++){
		cout<<a1[i]<<endl;
	}
	
	//inserting at start
	cout<<"Enter the element to be added at the first position: "<<endl;
	int f_ele; cin>>f_ele;
	updated_size=insert(a1,updated_size,f_ele,0);
	cout<<"The array is : "<<endl;
	for (int i=0;i<updated_size;i++){
		cout<<a1[i]<<endl;
	}
	
	//inserting at end
	cout<<"Enter the element to be added at the last position: "<<endl;
	int l_ele; cin>>l_ele;
	updated_size=insert(a1,updated_size,l_ele,updated_size);
	cout<<"The array is : "<<endl;
	for (int i=0;i<updated_size;i++){
		cout<<a1[i]<<endl;
	}
	
}
