#include<iostream>
using namespace std;
#include<climits>
#include<math.h>
int main(){
 int n;
 cin>>n;
 
int arr[n],a[n];
for(int i=0;i<n;i++){
	cin>>arr[i]>>a[i];
}
    for(int i=0;i<n;i++){
    	cout<<max(arr[i],a[i]) <<  endl;
    	
	}
}

