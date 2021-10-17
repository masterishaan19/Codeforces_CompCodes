#include<bits/stdc++.h>
#define ll long long
#define m 1000007
using namespace std;
void koli()
{ string s;cin>>s;
   int counta(0),countb(0),countc(0);
   for(int i=0;i<s.length();i++)
   {
       if(s[i]=='A')counta++;
       if(s[i]=='B')countb++;
       if(s[i]=='C')countc++;
       
   }if((counta+countc)==countb)
   {cout<<"YES"<<endl;}else cout<<"NO"<<endl;
}
int main()
{int t;
cin>>t;
while(t--)
{koli();}
  
return 0;
 
}