/**
 * Description: Floyd Warshall (Find the all pair shortest path distances)
 * Usage: See below O(N^3)
 */
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main(){
    int n;
    cin >> n;
    int Adj[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Adj[i][j] = INT_MAX;
        }
        Adj[i][i] = 0;
    }

    int countEdges;
    cin >> countEdges;
    for (int i = 0; i < countEdges; i++) {
        int a, b;
        int w;
        cin >> a >> b >> w;
        a--, b--;
        Adj[a][b] = min(Adj[a][b], w);
        Adj[b][a] = min(Adj[b][a], w);
    }

    int dist[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = Adj[i][j];
        }
    }
    // Floyd Warshall Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX and dist[k][j] != INT_MAX) {
                    if (dist[i][j] < dist[i][k] + dist[k][j]) {
                        dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}