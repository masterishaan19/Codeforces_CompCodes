#include<bits/stdc++.h>
#define ll long long
#define mn 10000007
using namespace std;
void koli()
{int n;
cin>>n;
int sum=0;
for(int i=1;i<=n;i++) {
	sum+=i;
}
int x,y;
cin>>x;
vector<int> ax;
for(int i=0;i<x;i++)
{int a;cin>>a;
ax.push_back(a);
}
cin>>y;
vector<int> ay;
for(int i=0;i<y;i++)
{int b;cin>>b;
ay.push_back(b);
}
vector<int> fnl=ax;;
fnl.insert(fnl.end(),ay.begin(),ay.end());
sort(fnl.begin(),fnl.end());
fnl.erase(unique(fnl.begin(),fnl.end()),fnl.end());
 
int sum2=0;
for(int i=0;i<fnl.size();i++)
{sum2+=fnl[i];
}
if(sum==sum2){cout<<"I become the guy."<<endl;}
else cout<<"Oh, my keyboard!"<<endl;
 
 
 
 
 
}
 
int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);
  //int t;
 // cin>>t;
 // while(t--)
   koli();
return 0;
 
}