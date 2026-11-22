class Solution {
public:
    int solve(int idx, int prev, vector<vector<int>>& pairs, vector<vector<int>>& dp){
        if(idx == pairs.size()) return 0 ;

        if(dp[idx][prev+1] != -1) {
            return dp[idx][prev+1] ;
        }

        int skip = solve(idx+1,prev,pairs,dp) ;

        int take = 0 ;
        
        if(prev == -1 || pairs[prev][1] < pairs[idx][0]) {
            take = 1 + solve(idx+1,idx,pairs,dp) ;
        }

        return dp[idx][prev+1] = max(skip,take) ;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size() ;

        vector<vector<int>> dp(n,vector<int>(n + 1,-1)) ;

        sort(pairs.begin(),pairs.end()) ;

        return solve(0, -1, pairs, dp) ;
    }
};