#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
			
		sort(arr,arr+n);
		reverse(arr,arr+n);
		
		int count = 0,flag = 0;
		while(x > 0)
		{
			if(count == n)
			{
				cout<<"-1\n";
				flag = 1;
				break;
			}
			x -= arr[count];
			count++;
		}
		if(flag == 1)
			continue;
		cout<<count<<"\n";
	}
}
