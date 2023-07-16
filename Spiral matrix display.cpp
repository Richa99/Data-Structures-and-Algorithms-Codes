#include<iostream>
using namespace std;

int main(){
	int n,m;
	cout<<"Enter the number of rows";
	cin>>n;
	cout<<"Enter the number of columns";
	cin>>m;
	int a[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	cout<<"The mtrix is:"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
//	cout<<"Spiral display of matrix"<<endl;
//	int row_srt=0,row_end=n-1,col_srt=0,col_end=m-1;
//	while(row_srt<=row_end && col_srt<=col_end){
//		
//		//row_srt
//		for(int col=col_srt;col<=col_end;col++){
//			cout<<a[row_srt][col]<<" ";
//		}
//		row_srt++;
//		cout<<endl;
//		//col end
//		for(int row=row_srt;row<=row_end;row++){
//			cout<<a[row][col_end]<<" ";
//		}
//		col_end--;
//		cout<<endl;
//		//row end
//		for(int col=col_end;col>=col_srt;col--){
//			cout<<a[row_end][col]<<" ";
//		}
//		row_end--;
//		cout<<endl;
//		//col srt
//		
//		for(int row=row_end;row>=row_srt;row--){
//			cout<<a[row][col_srt]<<" ";
//		}
//		col_srt++;
//		cout<<endl;
//	}

//transpose of a 2d matirix
	int temp;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i!=j && i>j){
				temp=a[i][j];
				a[i][j]=a[j][i];
				a[j][i]=temp;
			}
		}
	}
	cout<<"Tranpose of the matrix is: "<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	
	

}
