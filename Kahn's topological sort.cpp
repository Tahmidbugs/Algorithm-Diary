#include <bits/stdc++.h>
using namespace std;

// 5 7
// 1 4
// 1 2
// 4 2
// 2 3
// 4 6
// 4 5
// 5 6
// 1 4 2 3 5 6
int main(){
    
    int n,m; cin>>n>>m;
    map<int,vector<int>>adj; 
    map<int,int>incoming;
    
    for(int i=1; i<=n; i++)
        incoming[i]=0;
        
    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v;
        incoming[v]++;
        adj[u].push_back(v);
    }
    
    set<int>s;
    for(int i=1; i<=n; i++){
        if(incoming[i]==0)
            s.insert(i);
    }
    
    vector<int>output;
    while(!s.empty()){
        int x= *s.begin();
        s.erase(x);
        for(auto a: adj[x]){
            incoming[a]--;
            if(incoming[a]==0)
                s.insert(a);
        }
        output.push_back(x);
    }
    
    for(auto a: output)
        cout<<a<<" ";
    return 0;
}

