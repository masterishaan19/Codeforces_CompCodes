#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a1,a2,a3,b1,b2,b3;
		cin>>a1>>a2>>a3>>b1>>b2>>b3;
		
		if(a1 + a2 + a3 > b1 + b2 + b3){
			cout<<"Dragon\n";
		}
		else if(a1 + a2 + a3 < b1 + b2 + b3){
			cout<<"Sloth\n";
		}
		else
		{
			if(a1 > b1)
				cout<<"Dragon\n";
			else if(a1 < b1)
				cout<<"Sloth\n";
			else{
				if(a2 > b2)
					cout<<"Dragon\n";
				else if(a2 < b2)
					cout<<"Sloth\n";
				else
					cout<<"Tie\n";
			}
		}
	}
}
