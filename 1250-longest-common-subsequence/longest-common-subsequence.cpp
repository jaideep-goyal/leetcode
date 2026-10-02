class Solution {
public:
    int solve(int i , int j , string& s1 , string& s2 , vector<vector<int>>& dp) {

        int n = s1.size() ;
        int m = s2.size() ;

        if(i == n || j == m) {
            return 0 ;
        }
        if(dp[i][j] != -1) return dp[i][j] ;

        if(s1[i] == s2[j]) {
            return dp[i][j] = 1 + solve(i + 1 , j + 1 , s1 , s2 ,dp) ;
        }

        int take1 = solve(i + 1 , j , s1 , s2 , dp) ;
        int take2 = solve(i , j + 1 , s1 , s2 , dp) ;

        return dp[i][j] = max(take1 , take2) ;
    }
    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.size() ;
        int m = text2.size() ;
        vector<vector<int>> dp(n , vector<int>(m, -1)) ;
        return solve(0 , 0 , text1 , text2 , dp) ;
        
    }
};