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

vector<pair<ll, ll>> coco;

void dfs(vector<vl>& cute,vector<bool>& vis,string& reg,int start)
{
    vis[start]=true;
    if(reg[start]=='B'){coco[start].second++;}else{coco[start].first++;}
    for(int i=0;i<cute[start].size();i++)
    {
        if(!vis[cute[start][i]])
        {
            dfs(cute,vis,reg,cute[start][i]);
            coco[start].second+=coco[cute[start][i]].second;
            coco[start].first+=coco[cute[start][i]].first;
        }
    }
}

void funk()
{
    ll n;cin>>n;
    vector<vl> adj(n);
    map<ll,ll> pun;
    coco.assign(n, {0, 0});
    loop(i,n-1)
    {
        ll t;cin>>t;
        t--;
        pun[t]++;
        adj[t].pb(i+1);
    }
    string pew;cin>>pew;
    ll ct=0;
    vector<bool> cp(n,false);
    dfs(adj,cp,pew,0);
    loop(i,coco.size())
    {
        if(coco[i].first==coco[i].second)
        {
            ct++;
        }
    }
    cout<<ct<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        funk();
    }
    return 0;
}
