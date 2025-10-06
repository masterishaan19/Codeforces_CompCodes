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

        class Solution {
      public:
          vector<pair<int,int>> dxy = {{1,0},{0,1},{-1,0},{0,-1}};
          void bfs(vector<vector<int>> &hts,vector<vector<bool>> &vis,int n,int m,queue<pair<int,int>> &q){
              while(!q.empty()){
                  int x = q.front().first;
                  int y = q.front().second;
                  q.pop();
                  vis[x][y] = 1;
                  for(int i=0;i<4;i++){
                      int u = x+dxy[i].first;
                      int v = y+dxy[i].second;
                      if((u>=0&&v>=0&&u<n&&v<m) && !vis[u][v] && hts[u][v] >= hts[x][y]){
                          q.push({u,v});
                      }
                  }
              }
          }
          vector<vector<int>> pacificAtlantic(vector<vector<int>>& hts) {
              int n = hts.size();
              int m = hts[0].size();
              vector<vector<bool>> visP(n,vector<bool>(m,0)),visA(n,vector<bool>(m,0));
              queue<pair<int,int>> q;
              for(int i=0;i<n;i++){
                  q.push({i,0});
              }
              for(int i=0;i<m;i++){
                  q.push({0,i});
              }
              bfs(hts,visP,n,m,q);
              for(int i=0;i<n;i++){
                  q.push({i,m-1});
              }
              for(int i=0;i<m;i++){
                  q.push({n-1,i});
              }
              bfs(hts,visA,n,m,q);
              vector<vector<int>> ans;
              for(int i=0;i<n;i++){
                  for(int j=0;j<m;j++){
                      if(visP[i][j] == 1 && visA[i][j] == 1){
                          ans.push_back({i,j});
                      }
                  }
              }
              return ans;
          }
      };
void lets_do_it(){
  cout<<"Hello World"<<endl;
}

int main(){
    flash;
    ll num = 1;
    cin >> num;
    while (num--){
        //lets_do_it();
        Solution x = new Solution();
        cout<<x<<endl;
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / CLOCKS_PER_SEC << "ms" << endl;
}
