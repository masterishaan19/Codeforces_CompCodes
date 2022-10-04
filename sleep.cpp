#include<iostream>
using namespace std;
#include<climits>
#include<math.h>
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		if(arr[i]<7){
			cout<<"YES";
		}else if(arr[i]==7){
			cout<<"NO";
		}
		else{
			cout<<"NO";
		}
		cout<<endl;
	}

	
	
}

