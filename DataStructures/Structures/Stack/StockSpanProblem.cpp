/*
//Stock span implementation Naive Approach
#include<iostream>
#include<cstring>
using namespace std;
void calculateSpan(int price[],int n,int S[]){
	S[0]=1;
	for(int i=1;i<n;i++){
		S[i]=1;
		for(int j=i-1;(j>=0)&&(price[i]>=price[j]);j--)
			S[i]++;
	}
}
void printArray(int arr[], int n){
	for(int i=0;i<n;i++){
		 cout<<arr[i]<<" ";
	}
}
int main(){
	int price[]={10,4,5,90,120,80};
	int n=sizeof(price)/sizeof(price[0]);
	int S[n];
	
	calculateSpan(price,n,S);
	printArray(S,n);
}
*/

//StockSpanProblemLinear
#include<iostream>
#include<stack>
using namespace std;
void calculateSpan(int price[],int n,int S[]){
	stack<int> st;
	st.push(0);
	S[0]=1;
	for(int i=1;i<n;i++){
		while(!st.empty()&& price[st.top()]<=price[i])
			st.pop();
		S[i]=((st.empty())?(i+1):(i-st.top()));
		st.push(i);
	}
}
void print(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
int main(){
	int price[]={10,4,5,90,120,80};
	int n=sizeof(price)/sizeof(price[0]);
	int S[n];
	calculateSpan(price,n,S);
	print(S,n);
}