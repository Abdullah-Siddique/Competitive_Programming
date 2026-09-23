/*
1 -> 2 3 4 
2 -> 1 9
3 -> 1 7
4 -> 1 5 6 
5 -> 4 
6 -> 4 
7 -> 3 8 
8 -> 7
9 -> 2 10 11
10 -> 9
11 -> 9 

input:
11 10
1 2
1 3
1 4
2 9
3 7
4 5
4 6
7 8
9 10
9 11
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 2e5 + 5;
vector<ll> adj[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, e; 
    cin >> n >> e;
    for(ll i = 0; i < e; i++){
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> bfs; 
    vector<ll> d(n + 1, -1);//d[i] = distance of node i from source node(1)
    vector<ll> p(n + 1, -1); //p[i] = parent node of node i
    
    vector<bool> visited(n + 1, false);
    queue<ll> q;
    visited[1] = true;
    q.push(1);
    d[1] = 0;
    p[1] = -1; 
    while(!q.empty()){
        ll node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                q.push(neighbour);
                d[neighbour] = d[node] + 1;
                p[neighbour] = node;
            }
        }
    }
    cout << "BFS: \n";
    for(auto e : bfs) cout << e << ' ';
    cout << '\n';
    for(ll i = 1; i <= n; i++){
        cout << "Distance from source(1) to node " << i << " is " << d[i] << '\n';  
    }
    for(ll i = 1; i <= n; i++){
        cout << "Parent node of node " << i << " is " << p[i] << '\n';  
    }
    return 0;
}
