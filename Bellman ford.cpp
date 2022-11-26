

 #include <iostream>
 #include <cstdio>
 #include <bits/stdc++.h>
 #include <vector>
 using namespace std;



// struct edges {
//     int u;
//     int v;
//     long long w;
//     edges(int u, int v, long long w): u(u), v(v), w(w) {}
// };

int main(){
	int n, m; cin>>n>>m;

	vector<vector<int>> edge;

	for (int i = 0; i < m; i++) {
		int a, b, w; cin>>a>>b>>w;
		edge.push_back({a, b, w});
	}

	int parent[100];
	long long dist[100];
	for (int i = 0; i < n; i++) {
		parent[i] = 0;
		dist[i] = INT_MAX;
	}

	dist[0] = 0; // distance of source node = 0
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < edge.size(); j++) {
			int u = edge[j][0];
			int v = edge[j][1];
			long long w = edge[j][2];
			if (dist[u] != INT_MAX) {
				if (dist[v] > dist[u] + w){
					dist[v] = dist[u] + w;
					parent[v] = u;
				}
			}
		}
	}

	bool negCycleExists = false;
	for (int j = 0; j < edge.size(); j++) {
	    int u = edge[j][0];
		int v = edge[j][1];
		long long w = edge[j][2];
		if (dist[v] > (dist[u] + w)) {
			negCycleExists = true;
			break;
		}
	}

	if (negCycleExists) {
        cout << "Negative Cycle Exists";
	} else {
        for (int i = 0; i < n; i++) {
            cout << i << "=>" << dist[i] << endl;
        }
	}
}