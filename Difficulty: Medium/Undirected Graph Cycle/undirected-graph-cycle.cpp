class Solution {
public:

    bool isCycleDetect(int src, int par, vector<bool>& vis, vector<int> adj[]) {

        vis[src] = true;

        for (int v : adj[src]) {

            if (!vis[v]) {

                if (isCycleDetect(v, src, vis, adj))
                    return true;
            }
            else if (v != par) {
                return true;
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {

        vector<int> adj[V];

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(V, false);

        for (int i = 0; i < V; i++) {

            if (!vis[i]) {

                if (isCycleDetect(i, -1, vis, adj))
                    return true;
            }
        }

        return false;
    }
};