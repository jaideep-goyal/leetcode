
class Solution {
public:
    int mod = 1e9 + 7 ;
    int m, n ;
    vector<vector<int>> dp ;

    int dfs(int i, int j, vector<vector<int>>& grid) 
    {
        if (dp[i][j] != 0) 
        {
            return dp[i][j] ;
        }

        dp[i][j] = 1 ;

        int dx[] = {-1, 1, 0, 0} ;
        int dy[] = {0, 0, -1, 1} ;

        for (int k = 0 ; k < 4 ; k++) 
        {
            int x = i + dx[k] ;
            int y = j + dy[k] ;

            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] > grid[i][j]) 
            {
                dp[i][j] = (dp[i][j] + dfs(x, y, grid)) % mod ;
            }
        }

        return dp[i][j] ;
    }

    int countPaths(vector<vector<int>>& grid) {
        m = grid.size() ;
        n = grid[0].size() ;

        dp.assign(m, vector<int>(n, 0)) ;

        int ans = 0 ;

        for (int i = 0 ; i < m ; i++) 
        {
            for (int j = 0 ; j < n ; j++) 
            {
                ans = (ans + dfs(i, j, grid)) % mod ;
            }
        }

        return ans ;
    }
};
