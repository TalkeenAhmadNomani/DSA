class Solution
{
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
        vector<int> indegree(V, 0);
        queue<int> q;
        vector<int> ans;
        // making indegree

        for (int u = 0; u < V; u++)
        {
            for (auto &v : adj[u])
            {
                indegree[v]++;
            }
        }
        // pushing element, who have indegree is 0

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        // now bfs

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto &it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        return ans;
    }
};
