/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);

        // Build graph and calculate in-degree
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        // Add nodes with in-degree 0
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;

        // Kahn's Algorithm
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (int next : adj[node]) {
                indegree[next]--;

                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        return ans;
    }
};
