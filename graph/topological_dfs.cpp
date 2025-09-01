#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(int u, vector<bool> &vis, vector<vector<int>> &adj, stack<int> &st)
    {
        vis[u] = true;

        for (auto &v : adj[u])
        {
            if (!vis[v])
            {
                dfs(v, vis, adj, st);
            }
        }
        // After visiting all neighbors, push current node to stack
        st.push(u);
    }

public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        // Convert edge list to adjacency list
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        vector<bool> vis(V, false);
        stack<int> st;
        vector<int> ans;

        // Run DFS from each unvisited vertex
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                dfs(i, vis, adj, st);
        }

        // Pop from stack to get topological order
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
