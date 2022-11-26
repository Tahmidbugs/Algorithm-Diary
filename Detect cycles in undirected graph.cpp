#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;



bool hasCycle(unordered_map<char,vector<char>>graph, int i, set<int>visited, int parent){
    if(visited.count(i))
        return true;
    visited.insert(i);
    for(auto a: graph[i])
    {
        if(a!=parent && hasCycle(graph, a, visited,i ))
            return true;
    }
    return false;
    
}
bool hasCycle(unordered_map<char,vector<char>>graph){
    set<int>visited;
    
    for(auto a: graph){
        if(hasCycle(graph, a.first, visited,-1))
            return true;
    }
    return false;
}

int main(){
    unordered_map<char,vector<char>>graph;
    int n; cin>>n;
    while(n--){
        int a,b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cout<<hasCycle(graph);
    
}
