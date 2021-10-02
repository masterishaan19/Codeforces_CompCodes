//ThakurAnurag
//TemplateCode

// これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました

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
#define array_limit 1000010

bool prime[array_limit];

ll power(ll x,ll y){  
    ll res = 1;
    if (x == 0) return 0;
    while (y > 0){  
        if (y & 1)  
            res = (res*x);  
        y = y>>1;
        x = (x*x);  
    }  
    return res;  
}
 
ll ncr(ll n,ll r) 
{ 
    ll p = 1, k = 1; 
    if (n - r < r) 
        r = n - r; 
    if (r != 0) { 
        while (r) { 
            p *= n; 
            k *= r; 
            ll m = __gcd(p, k); 
            p /= m; 
            k /= m; 
            n--; 
            r--; 
        } 
    } 
    else
        p = 1; 
    return p ;
} 

void seive(){
	init(prime,true);
	prime[1] = false;
	for(ll i=2;i<=1e6;i++){
		if(prime[i]){
			for(ll j = i*i ; j<=1e6 ; j+=i){
				prime[j] = false;
			}
		}
	}
}

int main()
{
	long long int r,x,y,x1,y1;
	cin>>r>>x>>y>>x1>>y1;

    double dist;
    long long res;
    if(x==x1&&y==y1){
        cout<<0<<endl;
        return 0;
    }
    
    dist = sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
    dist -= 1e-12;
    r*=2;
    res = dist/r;
    cout<<res+1<<endl;
	return 0;
}