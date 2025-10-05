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
vector<pll> DxDy = {{-1,0},{1,0},{0,-1},{0,1}};
//                    SE     SW     NE     NW
vector<pll> DiaXY = {{1,1},{1,-1},{-1,1},{-1,-1}};

string path = "UDLR";
string alpha = "abcdefghijklmnopqrstuvwxyz";
string numeric = "0123456789";

bool compare(pair<ll, ll> v1, pair<ll, ll> v2){return v1.first < v2.first;}
bool powerof2(ll n){return n && !(n & (n-1));}

bool win(int a, int b) {
    return a > b;
}

void lets_do_it() {
    string s,t;
    cin>>s>>t;
    ll i = 0,j = 0;
    while(i<s.length() && j<t.length()){
        if(s[i] == t[j]){
            i++;
            j++;
        }else if(s[i] == '?'){
            s[i] = t[j];
            i++;
            j++;
        }else{
            i++;
        }
    }
    if(i>=s.length() && j<t.length()){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        for(int i=0;i<s.length();i++){
            if(s[i] == '?'){
                s[i] = 'a';
            }
        }
        cout<<s<<endl;
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
