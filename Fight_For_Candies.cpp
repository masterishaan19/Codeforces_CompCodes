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
#define pdl pair<double, ll>
#define mp make_pair
const ll GEN = 1e5 + 1, MOD = 1e9 + 7, OO = 1e18 + 10;

//          N  S  W  E
ll dx[] = {-1, 1, 0, 0}; // i-->Row
ll dy[] = {0, 0, -1, 1}; // j-->Column

ll diaX[] = {1,1,-1,-1};
ll diaY[] = {1,-1,1,-1};

string path = "UDLR";
string alpha = "abcdefghijklmnopqrstuvwxyz";
string numeric = "0123456789";

bool compare(pair<string, ll> v1, pair<string, ll> v2)
{
    return v1.second < v2.second;
}


bool powerof2(ll n) 
{
    return n && !(n & (n-1));
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

void lets_do_it() {
    ll a;
    cin>>a;
    ll sum = 0;
    vector<ll> v(a);
    for(int i=0;i<a;i++){
        cin>>v[i];
    }

    // 11
    // 3 1 4 1 5 9 2 6 5 3 5
    

    int i=0,j=a-1,c1 = 0,c2 = 0;
    int count = 0,st = 0;
    while(i<=j){
        if(count%2==0){
            //Aice
            ll cal = 0;
            while(cal<=st && i<=j){
                cal+=v[i];
                c1+=v[i];
                i++;
            }
            st = cal;
        }else{
            //Bob
            ll cal = 0;
            while(cal<=st && j>=i){
                cal+=v[j];
                c2+=v[j];
                j--;
            }
            st = cal;
        }
        count++;
    }
    cout<<count<<" "<<c1<<" "<<c2<<endl;
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
