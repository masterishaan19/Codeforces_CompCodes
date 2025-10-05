#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define endl "\n"
#define flash                          \
    ios_base ::sync_with_stdio(false); \
    cin.tie(NULL);                     \
    cout.tie(NULL);
#define cc continue
#define bb break
#define ssort(a) sort(a.begin(), a.end());
#define pll pair<ll, ll>
#define pdl pair<double, ll>
#define mp make_pair
const ll GEN = 1e5 + 1, MOD = 1e9 + 7, OO = 1e18 + 10;

//          N  S  W  E
ll dx[] = {-1, 1, 0, 0}; // i-->Row
ll dy[] = {0, 0, -1, 1}; // j-->Column

string path = "UDLR";
string alpha = "abcdefghijklmnopqrstuvwxyz";
string numeric = "0123456789";

bool compare(pair<ll, ll> v1, pair<ll, ll> v2)
{
    return v1.second > v2.second;
}

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


void lets_do_it(){
    ll a,b;
    cin>>a>>b;
    vector<vector<char>> v(a,vector<char>(b));
    ll count = 0,x,y;
    for(int i=0;i<a;i++){
        bool flag = true;
        for(int j=0;j<b;j++){
            cin>>v[i][j];
            if(v[i][j] == '#' && flag){
                count++;
                x = i;
                y = j;
                flag = false;
            }
        }
    }
    if(count == 1){
        cout<<x+1<<" "<<y+1<<endl;
    }else{
        ll to = x - count/2;
        ll idx = 0;
        count = 0;
        for(int i=0;i<b;i++){
            if(v[to][i] == '#'){
                idx = i;
                count++;
            }
        }
        cout<<to+1<<" "<<idx - count/2 + 1<<endl;
    }

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

