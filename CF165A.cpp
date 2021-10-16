#include<bits/stdc++.h>
#define ll long long
#define mn 10000007
using namespace std;
void koli()
{float n;
cin>>n;int flag(0);
float ang=360/(180-n);
int comp=(int)ang;
//cout<<ang<<" "<<comp<<endl;
if(ang==comp){cout<<"YES"<<endl;}
else cout<<"NO"<<endl;
}
int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);
  int t;
 cin>>t;
 while(t--)
  { koli();}
return 0;
 
}