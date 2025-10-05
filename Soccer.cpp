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

// Z-algorithm
vector<int> z_function_trivial(string s)
{
    int n = s.size();
    vector<int> z(n);
    for (int i = 1; i < n; i++)
    {
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            z[i]++;
        }
    }
    return z;
}

ll n,m;

void lets_do_it(){
    ll n,k;
    cin>>n>>k;
    map<ll,ll> m;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        m[x]++;
    }

    vector<ll> v;
    for(auto i:m){
        if(i.second >= k){
            // cout<<i.first<<endl;
            v.pb(i.first);
        }
    }
    if(v.size() == 0){
        cout<<-1<<endl;
        return ;
    }
    ssort(v);
    vector<pair<pair<ll,ll>,ll>> res;
    ll in = v[0];
    ll l=v[0],r=v[0],maxi = INT_MIN;
    for(int i=1;i<v.size();i++){
        if(abs(v[i-1]-v[i]) == 1){
            if(v[i] - in > maxi){
                maxi = v[i]-in;
                l = in;
                r = v[i];
            }
        }else{
            in = v[i];
        }
    }
    // for(auto i:res){
    //     cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<endl;
    // }

    cout<<l<<" "<<r<<endl;
}


int main(){
    flash;
    
    ll num = 1;
    cin>>num;
    while(num--){
        lets_do_it();
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / CLOCKS_PER_SEC << "ms" << endl;
}   

