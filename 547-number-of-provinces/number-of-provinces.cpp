#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int i, vector<vector<int>> &adj, vector<int> &vis)
    {
        vis[i] = 1;
        for (int next : adj[i])
        {
            if (vis[next] == 0)
            {

                dfs(next, adj, vis);
                
            }

        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        int m = isConnected[0].size();

        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {

                if (isConnected[i][j] == 1 && i != j)
                {

                    adj[i].push_back(j);

                }
            }
        }
        int count = 0;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++)
        {

            if (vis[i] == 0)
            {

                count++;
                dfs(i, adj, vis);

            }
        }
        return count;
    }
};