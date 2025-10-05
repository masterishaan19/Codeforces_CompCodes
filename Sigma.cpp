/*    /\_/\
 *   (= ._.)
 *   / >  \>
 */       //
 //Hi Stalker aajkal code bhi stalk karne lage?! :)
#include <bits/stdc++.h>
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
#define mp make_pair
const ll GEN = 1e6+1, MOD = 1e9+7,BW = 1e12+2, OO = 1e18+10;
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

bool compare(pll v1, pll v2) { return v1.first > v2.first; }
bool powerof2(ll n) { return n && !(n & (n - 1)); }


void lets_do_it(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>v(n,vector<ll>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    map<ll,ll> vis;
    vector<vector<ll>> sum(n,vector<ll>(m+1,0));
    for(int i=0;i<n;i++){
        ll idx = 0;
        ll summ = 0;
        for(int j=0;j<m;j++){
            sum[i][j+1] += sum[i][j]+v[i][j];
            if(sum[i][j+1] > summ){
                summ = sum[i][j+1];
                idx = i;
            }
        }
        vis[idx]++;
    }
    vector<pair<ll,ll>> fin(n);
    for(auto i:vis){
        fin.pb({i.second,i.first});
    }
    ll res = 0;
    sort(fin.begin(),fin.end(),compare);
    vector<ll>final;
    ll till = 0;
    for(int i=0;i<n;i++){
        ll x = fin[i].second;
        for(int j=0;j<m;j++){
            res += v[x][j];
            till += res;
        }
    }
    cout<<till<<endl;
}

int main(){
    flash;
    ll num = 1;
    cin >> num;
    while (num--){
        lets_do_it();
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / CLOCKS_PER_SEC << "ms" << endl;
}
