#include<iostream>
using namespace std;

void swap(int a[],int i,int j){
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}

int partition(int a[],int l,int r){
	int pivot=a[r];
	int i=l-1;
	for(int j=l;j<r;j++){
		if(pivot>a[j]){
			i++;
			swap(a,i,j);
		}
	}
	swap(a,i+1,r);
	return i+1;
}

void quicksort(int a[],int l,int r){
	
	if(l<r){
		int pi=partition(a,l,r);
		quicksort(a,l,pi-1);
		quicksort(a,pi+1,r);
	}
}

int main(){
	int n=6;
	int arr[n]={6,3,2,7,5,8};
	
	quicksort(arr,0,5);
	cout<<"Sorted array is: \n";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

