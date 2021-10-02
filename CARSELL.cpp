#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
#define ld long double
#define fo(i,s,e) for(int i=s;i<e;++i)
#define endl << "\n"
#define sp << " "
#define spp << " " <<
#define all(v) v.begin(),v.end()
#define al(v,n) v,v+n
#define lmax 9223372036854775807
#define lmin -9223372036854775808
#define ft first
#define sd second
#define pb push_back
#define pf push_pront
#define mod 1000000007
#define lower(str) transform(str.begin(), str.end(), str.begin(), ::tolower);
#define upper(str) transform(str.begin(), str.end(), str.begin(), ::toupper);
#define mset(a,b) memset(a,b,sizeof(a))
#define crap ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define PI acos(-1)

int main(){
//	crap ;
    int timer;
    cin >>timer;
    while(timer--){
    	ll n,i,ans=0 ;
    	cin >>n;
    	ll dta[n];
    	for(i=0;i<n;++i)
    		cin >>dta[i] ;
    	sort(al(dta,n),greater<int>());
    	i=0 ;
    	while(i < n && dta[i] > i){
    		ans = (ans + ( dta[i]-i ) )%mod ;
            i++ ;
        }
    	cout << ans endl ;
    }
}
