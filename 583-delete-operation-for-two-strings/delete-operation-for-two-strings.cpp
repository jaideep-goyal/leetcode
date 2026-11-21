class Solution {
public:
    // int solve(int i , int j , vector<vector<int>> dp , string& word1 , string& word2) {

    //     // if(i == word1.size()) return word2.size() - j ;
    //     // if(j == word2.size()) return word1.size() - i ;

    //     // if(dp[i][j] != -1) return dp[i][j] ;
    //     // if(word1[i] == word2[j]) return dp[i][j] = solve(i + 1 , j + 1 , dp , word1 , word2) ;

    //     // int delete1 = solve(i + 1 ,j , dp , word1 , word2) ;
    //     // int delete2 = solve(i , j + 1 , dp , word1 , word2) ;
    //     // return dp[i][j] = 1 + min(delete1 ,delete2) ;

    // }
    int minDistance(string word1, string word2) {
        int m = word1.size() ;
        int n = word2.size() ;

        // vector<vector<int>> dp(m , vector<int>(n , -1)) ;
        // return solve(0 , 0 , dp , word1 , word2) ;
        vector<vector<int>> dp(m + 1 , vector<int>(n + 1 , 0)) ;
        for(int i = 0 ; i <= m ; i++) {
            dp[i][n] = m - i ;
        }
        for(int j = 0 ; j <= n ; j++) {
            dp[m][j] = n - j ;
        }

        for(int i = m - 1 ; i >= 0 ; i--) {
            for(int j = n - 1 ; j >= 0 ; j--) {

                if(word1[i] == word2[j]) dp[i][j] = dp[i + 1][j + 1] ;
                else {
                    dp[i][j] = 1 + (min(dp[i + 1][j] , dp[i][j +1])) ;
                }
            }
        }

        return dp[0][0] ;   
    }
};