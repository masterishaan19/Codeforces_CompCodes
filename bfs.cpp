#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> v[], int n, int root) {
  bool visited[n];

  for(int i = 0; i < n; i++)
    visited[i] = false;

  queue<int> q;
  visited[root] = true;
  q.push(root);
  while(!q.empty()) {
    int i = q.front();
    q.pop();
    cout << i << " ";
    
    for(int j = 0; j < v[i].size(); j++)
      if(!visited[v[i][j]]) {
        visited[v[i][j]] = true;
        q.push(v[i][j]);
      }
  }
}

int main(int argc, char const *argv[]) { 
  int n, e;

  cin >> n >> e;
  vector<int> v[n];

  for(int i = 0; i < e; i++) {
    int x, y;
    cin >> x >> y;
    v[x - 1].push_back(y - 1);
  }

  bfs(v, n, 0);
  return 0;
}
