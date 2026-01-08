class Solution
{
    public:
        int dp[505][505];
    int solve(int i, int j, vector<int> &a, vector<int> &b)
    {
        if (i == a.size() || j == b.size())
            return INT_MIN;
        if (dp[i][j] != -1)
            return dp[i][j];
        int take = a[i] *b[j];
        int next = solve(i + 1, j + 1, a, b);
        if (next != INT_MIN)
            take += max(0, next);
        int skipA = solve(i + 1, j, a, b);
        int skipB = solve(i, j + 1, a, b);
        return dp[i][j] = max({ take,
            skipA,
            skipB });
    }

    int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, nums1, nums2);
    }
};