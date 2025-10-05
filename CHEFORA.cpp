#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define mod 1000000007
#define exp pow(10,-9)
#define F first
#define S second
#define PB push_back 
#define MP make_pair
#define daman ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
vector<lli>palin;
vector<lli>sumPalin;
lli createPalindrome(int input, int b)
{
    lli n = input;
    lli palin = input;
    
    n /= b;
 
    while (n > 0)
    {
        palin = palin * b + (n % b);
        n /= b;
    }
    return palin;
}

void generatePalindromes()
{
   	lli number;
 
    lli i = 1;
    while (1)
    {
    	number = createPalindrome(i,10);
        palin.push_back(number);
        i++;
        
        if(palin.size() == 100011)
        	return;
    }
}
lli fastpow(lli base,lli pow)
{
	lli res = 1;
	
	while(pow)
	{
		if(pow%2 == 1)
			res = ((res%mod)*(base%mod))%mod;
			
		base = ((base%mod) * (base%mod))%mod;
		pow /= 2;
	}	
	return res;
}
main() { 
//	getchar();
	daman;
	
	generatePalindromes();
	
//	for(int i=0;i<palin.size();i++)
//		cout<<palin[i]<<" ";

	sumPalin.push_back(1);
	
	for(int i=1;i<palin.size();i++)
		sumPalin.push_back(sumPalin[i-1] + palin[i]);
		
//	for(int i=0;i<palin.size();i++)
//		cout<<sumPalin[i]<<" ";
	
	int q;
	cin>>q;
	while(q--)
	{
		lli l,r;
		cin>>l>>r;
		
		lli sum = 0;
	
		sum = sumPalin[r-1] - sumPalin[l-1];
			
		lli res = fastpow(palin[l-1],sum);
		
		cout<<res<<"\n";
	}
}
