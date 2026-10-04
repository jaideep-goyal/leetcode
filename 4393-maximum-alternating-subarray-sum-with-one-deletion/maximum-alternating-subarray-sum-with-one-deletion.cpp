class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        int n = nums.size() ;

        vector<vector<vector<long long>>> dp(n + 1 ,vector<vector<long long>>(2 , vector<long long>(2 , 0))) ;

        // Fill DP from right to left
        for(int i = n - 1 ; i >= 0 ; i--) {

            for(int parity = 0 ; parity < 2 ; parity++) {

                for(int del = 0 ; del < 2 ; del++) {

                    // Calculate current value
                    long long val ;

                    if(parity == 0) {
                        val = nums[i] ;
                    }
                    else {
                        val = -nums[i] ;
                    }

                    int nextparity = 1 - parity ;

                    // Take current element
                    long long take = val + dp[i + 1][nextparity][del] ;

                    // Initially take current element
                    long long ans = max(0LL , take) ;

                    // Delete current element
                    if(del == 0) {
                        long long skip = dp[i + 1][parity][1] ;
                        ans = max(ans , skip) ;
                    }

                    // Store answer
                    dp[i][parity][del] = ans ;
                }
            }
        }

        // Try starting subarray from every index
        long long ans = LLONG_MIN ;

        for(int i = 0 ; i < n ; i++) {

            long long curr = nums[i] + dp[i + 1][1][0] ;

            ans = max(ans , curr) ;
        }

        return ans ;
    }
};