/*
class Solution {
public:
    int mod = 1000000007;
    int solve(int i,int j,int rem,int n,int m,vector<vector<int>>& grid,int
k,vector<vector<vector<int>>>&dp){ if(i>=n || j>=m){ return 0;
        }
        rem=(rem+grid[i][j])%k;
        if(i==n-1 && j==m-1){
            return (rem==0);
        }
        if(dp[i][j][rem] != -1) return dp[i][j][rem];
        int right=solve(i,j+1,rem,n,m,grid,k,dp);
        int down=solve(i+1,j,rem,n,m,grid,k,dp);
        return dp[i][j][rem]=(right+down)%mod;


    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k,
-1))); return solve(0,0,0,n,m,grid,k,dp);

    }
};
*/
// class Solution {
// public:
//     int numberOfPaths(vector<vector<int>>& grid, int k) {
//         int n = grid.size(), m = grid[0].size();
//         const int mod = 1e9 + 7;
//         vector<vector<vector<int>>> dp(
//             n, vector<vector<int>>(m, vector<int>(k, 0)));
//         int startrem = grid[0][0] % k;
//         dp[0][0][startrem] = 1;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (i == 0 && j == 0) {
//                     continue;
//                 }
//                 for (int r = 0; r < k; r++) {
//                     long long ways = 0;
//                     if (i > 0) {
//                         ways += dp[i - 1][j][r];
//                     }
//                     if (j > 0) {
//                         ways += dp[i][j - 1][r];
//                     }
//                     if (ways == 0)
//                         continue;
//                     int newrem = (r + grid[i][j]) % k;
//                     dp[i][j][newrem] = (dp[i][j][newrem] + ways) % mod;
//                 }
//             }
//         }
//         return dp[n - 1][m - 1][0];
//     }
// };

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        const int mod = 1e9 + 7;
        vector<vector<int>> prev(m, vector<int>(k, 0));
        vector<vector<int>> curr(m, vector<int>(k, 0));
        int startrem = grid[0][0] % k;
        prev[0][startrem] = 1;
        for (int j = 1; j < m; j++) {
            for (int r = 0; r < k; r++) {
                if (prev[j - 1][r]) {
                    int newrem = (r + grid[0][j]) % k;
                    prev[j][newrem] = (prev[j][newrem] + prev[j - 1][r]) % mod;
                }
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++){
                for (int r = 0; r < k; r++){
                    curr[j][r] = 0;
                }
            }
            for (int j = 0; j < m; j++) {
                for (int r = 0; r < k; r++) {
                    long long ways = 0;
                    if (i > 0) {
                        ways += prev[j][r];
                    }
                    if (j > 0) {
                        ways += curr[j - 1][r];
                    }
                    if (ways == 0)
                        continue;
                    int newrem = (r + grid[i][j]) % k;
                    curr[j][newrem] = (curr[j][newrem] + ways) % mod;
                }
                
            }
            prev=curr;
        }
        return prev[m - 1][0];
    }
};
