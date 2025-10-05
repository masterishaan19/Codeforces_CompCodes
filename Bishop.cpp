/*     /\_/\
 *   (= ._. )
 *   / >  \>
 */       //
 //Hi Stalker aajkal code bhi stalk karne lage?! :)
#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define pb push_back
#define endl "\n"
#define flash                          \
    ios_base ::sync_with_stdio(false); \
    cin.tie(NULL);                     \
    cout.tie(NULL);
#define ssort(a) sort(a.begin(), a.end());
#define pll pair<ll, ll>
// #define mp make_pair
const ll GEN = 1e7+1, MOD = 1e9+7,BW = 1e12+2, OO = 1e18+10;
//                    N       S        W        E
vector<pll> Dxy = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
//                   SE      SW        NE       NW
vector<pll> DXY = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
// This Mark all the Directions
vector<pll> Compass = {{-1, 0}, {1, 0}, {0, -1}, {0, 1},{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

string path = "UDLR";
string alpha = "abcdefghijklmnopqrstuvwxyz";
string numeric = "0123456789";
string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

/*
 ██████╗██╗  ██╗███████╗███████╗████████╗███████╗██████╗      ██╗  ██╗██╗███╗   ██╗ ██████╗ 
██╔════╝██║  ██║██╔════╝██╔════╝╚══██╔══╝██╔════╝██╔══██╗     ██║ ██╔╝██║████╗  ██║██╔════╝ 
██║     ███████║█████╗  ███████╗   ██║   █████╗  ██████╔╝     █████╔╝ ██║██╔██╗ ██║██║  ███╗
██║     ██╔══██║██╔══╝       ██║   ██║   ██╔══╝  ██╔══██╗     ██╔═██╗ ██║██║╚██╗██║██║   ██║
╚██████╗██║  ██║███████╗███████║   ██║   ███████╗██║  ██║     ██║  ██╗██║██║ ╚████║╚██████╔╝
 ╚═════╝╚═╝  ╚═╝╚══════╝╚══════╝   ╚═╝   ╚══════╝╚═╝  ╚═╝     ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝ ╚═════╝ 
*/

bool compare(pll v1, pll v2) { 
    if(v1.first == v2.first){
        return v1.second < v2.second;
    }
    return v1.first < v2.first;
}
bool powerof2(ll n) { return n && !(n & (n - 1)); }

//to align the second element of a pair in ascending order!!
bool compare(pair<ll,ll> p1 , pair<ll,ll> p2){
return p1.second>p2.second;
}
/*
//Fibonacci series by DP!!!!!
int fib(ll n,ll dp[]){
    if(n==0 || n==1){
        return n;
    }

    if(dp[n]!=0){//Turning poinjt in DP!!
        return dp[n];
    }

    ll ans;
    ans=fib(n-1,dp)+fib(n-2,dp);
    return dp[n]=ans;//Storing the value in DP array!!!!
}*/

/*int same(int a,int b,string s,int k){
    for(int i=a;i<b;i++){
      if(s[i]==s[i+1]){
            same(i+1,b,s,k);
            return k++;
      }else{
            return 0;
      }
   }
}*/

bool ispalin(string a){
    for(int i=0;i<a.length()/2;i++){
        if(a[i]!=a[a.length()-1-i]){
            return false;
        }
    }
    return true;
}

string reverse(string k){
    char l[k.length()];
    ll u=0;
    for(int i=k.length()-1;i>=0;i--){
        l[u]=k[i];
        u++;
    }
    return l;
}

int main(){
    flash;
    ll num;
    cin>>num;
    for(int i=0;i<num;i++){
        char a[8][8];
        for(int j=0;j<8;j++){
            for(int k=0;k<8;k++){
                cin>>a[j][k];
            }
        }
        ll count=0,k=0;
        for(int j=0;j<8;j++){
            for(k=0;k<8;k++){
                if(a[j][k]=='#'&&a[j][k+1]=='.'&&a[j][k+2]=='#'){
                    count++;
                    break;
                }
            }
            if(count==1){
                cout<<j+2<<" "<<k+2<<endl;
                break;
            }
        }
}
}
