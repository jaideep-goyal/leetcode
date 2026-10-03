class Solution {
public:
    int solve(int i , string& s , vector<int>& dp) {

        int ans = 0 ;

        if(i < 0) return 0 ;

        if(dp[i]!=-1) return dp[i] ;

        if(s[i] == '(') return dp[i] = 0 ;

        //current char is ')' && prev char is '('
        if(i > 0 && s[i - 1] == '(') {
            ans = 2 + solve(i - 2 , s , dp) ;
        }
        
        //prev char is also ')'
        else if(i > 0 && s[i - 1] == ')') {
            int len = solve( i - 1 , s , dp) ;
            //check char just before that valid substr
            int j = i - len - 1 ;

            if(j >= 0 && s[j] == '(') {
                ans = len + 2 + solve( j - 1 , s , dp) ;
            }
        }

        return dp[i] = ans ;

    }
    int longestValidParentheses(string s) {

        int n = s.size() ;
        vector<int> dp(n , -1) ;
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++) {
            ans = max(ans , solve(i , s , dp)) ;
        }
        return ans ;
    }
};