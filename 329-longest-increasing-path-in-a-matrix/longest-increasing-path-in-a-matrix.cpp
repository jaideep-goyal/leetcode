class Solution {
public:
    int n , m ;
    vector<vector<int>> dp ;
    int dx[4] = {-1 , 1 , 0 , 0} ;
    int dy[4] = {0 , 0 , -1 ,1} ;

    int dfs(int i , int j , vector<vector<int>> & matrix) {

        if(dp[i][j] != -1) return dp[i][j] ;

        dp[i][j] = 1 ;

        for(int k = 0 ; k < 4 ; k++) {

            int nx = i + dx[k] ;
            int ny = j + dy[k] ;

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] > matrix[i][j]) {

                dp[i][j] = max(dp[i][j] , 1 + dfs(nx , ny ,matrix)) ;
            }
        }
        return dp[i][j] ;

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        n = matrix.size() ;
        m = matrix[0].size() ;
        dp.assign(n , vector<int>(m , -1)) ;

        int ans = 0 ;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                ans = max(ans , dfs(i , j , matrix)) ;
            }
        }

        return ans ;      
    }
};