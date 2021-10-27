#include<bits/stdc++.h>
using namespace std;
int main(){
	char str[100];
	cin >> str;
	int len = strlen(str);
	long long int num = 0;
	long long int val = 1;
	cout << "Length : " << len << "\n";
	for(int i=len-1; i>=0; i--){
		if(str[i] == '0' || str[i] == '1'){
			num = num + val*(str[i] - '0');
			val = val * 2;
		}else{
			cout << "Error....";
			exit(0);
		}
	}
	cout << "Binary number to decimal is : ";
	cout << num;
}

