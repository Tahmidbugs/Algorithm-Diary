#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

bool detectCycles(std::unordered_map<char, std::vector<char>> graph, unordered_set<int> &visited, unordered_set<int> visiting, char a)
{
  if(visiting.count(a))
    return true;
  if(visited.count(a))
    return false;
  
  visiting.insert(a);
  
  for(auto x: graph[a])
    if(detectCycles(graph, visited, visiting,x))
      return true;
      
  visiting.erase(a);
  visited.insert(a);
  return false;
}


bool hasCycle(std::unordered_map<char, std::vector<char>> graph) {
  unordered_set<int> visited;
  unordered_set<int> visiting;
  
  
  for(auto a: graph)
  {
    if(detectCycles(graph, visited, visiting, a.first))
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
       
    }
    cout<<hasCycle(graph);
}
