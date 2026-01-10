class Solution {
public:
    int dp[1001][1001];

    int solve(int i, int j, string &s1, string &s2) {
        if (i == s1.size()) {
            int sum = 0;
            for (int k = j; k < s2.size(); k++)
                sum += s2[k];
            return sum;
        }

        if (j == s2.size()) {
            int sum = 0;
            for (int k = i; k < s1.size(); k++)
                sum += s1[k];
            return sum;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j]) {
            return dp[i][j] = solve(i + 1, j + 1, s1, s2);
        }

        int del1 = s1[i] + solve(i + 1, j, s1, s2);
        int del2 = s2[j] + solve(i, j + 1, s1, s2);

        return dp[i][j] = min(del1, del2);
    }

    int minimumDeleteSum(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s1, s2);
    }
};
