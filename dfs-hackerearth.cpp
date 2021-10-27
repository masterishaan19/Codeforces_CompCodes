
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int
#define fo(i,a,n) for(ll i=a;i<n;i++)
#define fo2(i,a,n) for(ll i=n;i>=a;i--)
#define endl "\n"
#define sp " "
#define f first
#define s second
#define pb push_back
#define buffer ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define lower(str) transform(str.begin(), str.end(), str.begin(), ::tolower);
#define upper(str) transform(str.begin(), str.end(), str.begin(), ::toupper);
#define init(arr,val) memset(arr,val,sizeof(arr))

void dfs(int s,vector<vector<ll> > &adj , vector<bool> &visited ){
	visited[s] = true;
	fo(i,0,adj[s].size()){
		if(!visited[adj[s][i]]){
			dfs(adj[s][i],adj,visited);
		}
	}
}

int main()
{
	ll nodes,edges;
	cin>>nodes>>edges;

	vector<vector<ll> > adj;
	adj.assign(nodes+1,vector<ll> ());

	vector<bool> visited;
	visited.assign(nodes+1,false);

	ll x,y;
	fo(i,0,edges){
		cin>>x>>y;
		adj[x].pb(y);
//		adj[y].pb(x);
	}

	ll count =0 ;
	fo(i,1,nodes+1){
		if(visited[i] == false){
			dfs(i,adj,visited);
			count++;
		}
		fo(i,1,nodes+1){
			cout << visited[i] << sp;
		}
		cout<<endl;
	}
	cout<< " no of connected components : "<< count << endl;
	return 0;
}

