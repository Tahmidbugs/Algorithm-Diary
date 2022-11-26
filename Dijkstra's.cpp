/**
 * Description: Dijkstra (Find shortest path from single source)
 * Usage: dijkstra O((V + E) lg(V))
 * Source: https://github.com/dragonslayerx
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 4 4 
// 0 1 3
// 1 2 3
// 1 3 6
// 1 2 1
	
void dijkstra(vector<vector<pair<int,int>>>&G, int vertexCount, int src, vector<int> &dist);
int main(){
	int n, m; cin>>n>>m;

	vector<vector<pair<int,int>>> edge(m);

	for (int i = 0; i < m; i++) {
		int a, b, w; cin>>a>>b>>w;
		edge[a].push_back({b, w});
	}

	int parent[100];
	vector<int>dist(100);
	for (int i = 0; i < n; i++) {
		parent[i] = 0;
		dist[i] = INT_MAX;
	}
	
	dijkstra(edge,n,0,dist);
	for(int i=0; i<n; i++)
	    cout<<dist[i]<<" ";
}
	
	
void dijkstra(vector<vector<pair<int,int>>>&G, int vertexCount, int src, vector<int>&dist){
    
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>>>pq;
    set<int>visited;

    for (int i = 0; i < vertexCount; i++) {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;
    pq.push(make_pair(0, src));
    while (!pq.empty()){
        pair<int, int> tp = pq.top();
        pq.pop();
        int node = tp.second;
        int d = tp.first;
        if (!visited.count(node)) {
            visited.insert(node);
            for (int i = 0; i < G[node].size(); i++) {
                int v = G[node][i].first;
                int w = G[node][i].second;
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
    }
}