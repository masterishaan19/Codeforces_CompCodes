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

bool compare(pair<string,ll> m1,pair<string,ll> m2) { return m1.second > m2.second; }
bool powerof2(ll n) { return n && !(n & (n - 1)); }

void lets_do_it(){
    ll a;
    cin >> a;
    vector<ll> v(a + 1, 0);
    string s;
    vector<ll> res(a + 1, -1);
    vector<bool> vis(a + 1, false);
    
    for(int i = 1; i <= a; i++){
        cin>>v[i];
    }
    cin >> s;
    for(int i = 1; i <= a; i++){
        if(res[i] != -1){
            cout << res[i] << " ";
            continue;
        }
        if(v[i] == i){
            res[i] = (s[i - 1] == '0') ? 1 : 0;
            cout << res[i] << " ";
            vis[i] = true;
            continue;
        }
        ll j = i, count = 0;
        vector<ll> cycle;

        while(!vis[j]){
            vis[j] = true;
            cycle.push_back(j);
            if(s[j - 1] == '0') count++;
            j = v[j];
        }

        for(auto &idx : cycle){
            res[idx] = count;
        }

        cout << res[i] << " ";
    }
    
    cout << endl;
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
