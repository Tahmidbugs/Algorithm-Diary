#include <bits/stdc++.h>
using namespace std;
#define ADJ vector<vector<pair<int,int>>>
#define ELEM tuple<double,int,int>
#define PQ priority_queue<ELEM, vector<ELEM>, greater<ELEM>>



void add_vertex(int u, PQ &pq, ADJ &adj, set<int> &vis) {
    for(auto [v, w] : adj[u])
    if(vis.find(v) == vis.end())
    pq.push({w,u,v});
}
double mst_cost(int n, ADJ &adj) {
    set<int> vis({0}); PQ pq;
    add_vertex(0, pq, adj, vis);
    double cost = 0;
    while(not pq.empty() and vis.size() < n) {
    auto [w, u, v] = pq.top(); pq.pop();
    if(vis.find(v) == vis.end()) {
        cost += w;
        vis.insert(v);
        add_vertex(v, pq, adj, vis);
    }
    }

    return cost;
}
// 5 6
// 0 1 2
// 1 2 15
// 1 3 4
// 0 2 3
// 3 4 9 
// 2 9 13
// 18--output
int main(){
    
    int n,m; cin>>n>>m;
    ADJ ad(n);
    
    while(m--){
        int a,b,w; cin>>a>>b>>w;
        ad[a].push_back({b,w});
    }
    cout<<mst_cost(n,ad);
    return 0;
}

