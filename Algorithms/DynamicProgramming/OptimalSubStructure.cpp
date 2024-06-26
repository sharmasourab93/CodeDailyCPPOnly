#include<iostream>
#include<stdlib.h>
using namespace std;
//Recursive implementation for calculatig the LIS
int _lis(int arr[],int n, int *max_lis_length){
	//base case
	if(n==1) return 1;
	int current_lis_length=1;
	for(int i=0;i<n-1;i++){
		//Recursively calculate the length of the LIS
		//ending at arr[i]
		int subproblem_lis_length=_lis(arr,i,max_lis_length);
		//check if appending arr[n-1] to the LIS
		//ending at arr[i] gives us an LIS ending at
		//arr[n-1] which is longer than the previously 
		//calculated LIS ending at arr[n-1]
		if(arr[i]<arr[n-1] && current_lis_length<(1+subproblem_lis_length)){
			current_lis_length=1+subproblem_lis_length;
		}
	}
	//Check if currently calculated LIS ending at 
	//arr[n-1] is longer than the previously calculated 
	//LIS and update max_lis_length accordingly 
	if(*max_lis_length<current_lis_length){
		*max_lis_length=current_lis_length;
	}
	return current_lis_length;
}
//The wrapper function for _lis()
int lis(int arr[], int n){
	int max_lis_length=1; //stores the final LIS
	//max_lis_length is passed as a reference belwo 
	//so that it can maintain its value
	//between the recursive calls
	_lis(arr,n, &max_lis_length);
	return max_lis_length;
}
//Driver program to test the function above
int main(){
	int arr[]={10,22,9,33,21,50,41,60};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<"Length of LIS is "<<lis(arr,n);
}
