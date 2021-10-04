//ThakurAnurag
//TemplateCode

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int
#define fo(i,a,n) for(ll i=a;i<n;i++)
#define fo2(i,a,n) for(ll i=n;i>=a;i--)
#define endl "\n"
#define sp " "
#define f first
#define s second
#define pb push_back
#define buffer ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define lower(str) transform(str.begin(), str.end(), str.begin(), ::tolower);
#define upper(str) transform(str.begin(), str.end(), str.begin(), ::toupper);
#define init(arr,val) memset(arr,val,sizeof(arr))
#define vecl(v) vector<ll> v
#define vecs(v) vector<string> v
#define vecp(v) vector < pair <ll,ll> > v

int main()
{
	ll n,a,b,c;
	cin>>n>>a>>b>>c;

	ll dp[10000];
	fo(i,1,n+1) dp[i] = INT_MIN;
	dp[0] = 0;
	fo(i,1,n+1){
		if(i>=a) dp[i] = max(dp[i-a]+1,dp[i]);
		if(i>=b) dp[i] = max(dp[i-b]+1,dp[i]);
		if(i>=c) dp[i] = max(dp[i-c]+1,dp[i]);
	}
	cout<<dp[n]<<endl;
	return 0;
}