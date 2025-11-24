class Solution
{
    public:
        void dfs(int u, vector<vector < int>> &isConnected, vector< int > &vis)
        {
            vis[u] = 1;
            int n = isConnected.size();
            for (int v = 0; v < n; ++v)
                if (isConnected[u][v] && !vis[v])
                    dfs(v, isConnected, vis);
        }

    int findCircleNum(vector<vector < int>> &isConnected)
    {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int provinces = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!vis[i])
            {
                ++provinces;
                dfs(i, isConnected, vis);
            }
        }
        return provinces;
    }
};