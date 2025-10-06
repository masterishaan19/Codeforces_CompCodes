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
#define cc continue
#define bb break
#define ssort(a) sort(a.begin(), a.end());
#define pll pair<ll, ll>
#define mp make_pair
const ll GEN = 2e5 + 1, MOD = 1e9 + 7, OO = 1e18 + 10;
//                     N     S     W      E
vector<pll> Dxy = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
//                    SE     SW     NE     NW
vector<pll> DiaXY = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

string path = "UDLR";
string alpha = "abcdefghijklmnopqrstuvwxyz";
string numeric = "0123456789";

bool compare(pair<char,ll> v1, pair<char,ll> v2) { return v1.second > v2.second; }
bool powerof2(ll n) { return n && !(n & (n - 1)); }


void lets_do_it(){
    ll a;
    cin>>a;
    string s;
    cin>>s;
    map<char,ll> m;
    set<char> ss;
    for(int i=0;i<a;i++){
        m[s[i]]++;
        ss.insert(s[i]);
    }
    vector<pair<char,ll>> v;
    for(auto i:m){
        v.pb(mp(i.first,i.second));
    }
    ll count = ss.size();
    while(count>0){
        for(int i=0;i<v.size();i++){
            cout<<v[i].first;
            v[i].second--;
            if(v[i].second == 0){
                count--;
                v.erase(v.begin() + i);
            }
        }
    }
    cout<<endl;
}

int main(){
    flash;
    ll num = 1;
    cin>>num;
    while (num--){
        lets_do_it();
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / CLOCKS_PER_SEC << "ms" << endl;
}
