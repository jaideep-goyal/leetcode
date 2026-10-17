#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    // vector<vector<int>> dp ;
    // int n , m ;

    // int solve(vector<vector<int>>& matrix , int i , int j) 
    // {

    //     if(j < 0 || j >= m) return INT_MAX ;
    //     if(i == 0) return matrix[0][j] ;

    //     if(dp[i][j] != -1) return dp[i][j] ;

    //     int upleft = solve(matrix , i -1 , j - 1) ;
    //     int up = solve(matrix , i - 1 , j) ;
    //     int upright = solve(matrix , i - 1 , j + 1) ;

    //     int best =  min({upleft , up , upright}) ;

    //     if(best == INT_MAX) return dp[i][j] = INT_MAX ;
    

    //     return dp[i][j] = matrix[i][j] + best ;

    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size() ;
        int m = matrix[0].size() ;

        // dp.assign(n , vector<int>(m , -1)) ;
        int ans = INT_MAX ;

        // for(int j = 0 ; j < m ; j++)
        // {
        //     ans = min(ans , solve(matrix , n - 1 , j)) ;
        // }
        // return ans ;
        
        vector<vector<int>> dp(n , vector<int> (m , 0)) ;

        for(int j = 0 ; j < m ; j++) 
        {
            dp[0][j] = matrix[0][j] ;
        }

        for(int i = 1 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                int up = dp[i - 1][j] ;
                int upleft = (j > 0) ? dp[i - 1][j - 1] : INT_MAX ;
                int upright = (j < m - 1) ? dp[i - 1][j + 1] : INT_MAX ;
                dp[i][j] = matrix[i][j] + min({up , upleft , upright}) ;
            }
        }

        for(int j = 0 ; j < m ; j++)
        {
            ans = min(ans , dp[n - 1][j]) ;
        }

        return ans ;

    }
};