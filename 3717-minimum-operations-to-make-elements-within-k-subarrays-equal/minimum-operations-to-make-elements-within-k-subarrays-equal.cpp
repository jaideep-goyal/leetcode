class Solution {
public:
    vector<vector<long long>> dp;
    vector<long long> cost;
    int n, x;

    const long long INF = 1e18;

    // DP: Minimum cost to select j non-overlapping windows
    // starting from index i.
    long long solve(int i, int j) {
        // No more windows are required.
        if (j == 0) {
            return 0;
        }

        // Not enough elements left to select j windows.
        if (i >= n || n - i < j * x) {
            return INF;
        }

        // Return already calculated answer.
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Option 1: Skip the current window.
        long long ans = solve(i + 1, j);

        // Option 2: Select the window starting at i.
        // Move i by x to ensure windows don't overlap.
        long long take = solve(i + x, j - 1);

        // Add current window cost if selection is possible.
        if (take != INF) {
            ans = min(ans, cost[i] + take);
        }

        return dp[i][j] = ans;
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        n = nums.size();
        this->x = x;

        // low stores the smaller half of the window.
        // high stores the larger half.
        // Median is the largest element of low.
        multiset<int> low, high;

        // Sum of elements in low and high.
        long long sum1 = 0, sum2 = 0;

        // Maintain equal halves (low can have one extra element).
        auto balance = [&]() {
            int need = (low.size() + high.size() + 1) / 2;

            // Move largest element of low to high.
            while (low.size() > need) {
                int val = *low.rbegin();
                low.erase(prev(low.end()));
                sum1 -= val;

                high.insert(val);
                sum2 += val;
            }

            // Move smallest element of high to low.
            while (low.size() < need) {
                int val = *high.begin();
                high.erase(high.begin());
                sum2 -= val;

                low.insert(val);
                sum1 += val;
            }
        };

        // Insert a new element into the correct half.
        auto add = [&](int val) {
            if (low.empty() || val <= *low.rbegin()) {
                low.insert(val);
                sum1 += val;
            }
            else {
                high.insert(val);
                sum2 += val;
            }

            balance();
        };

        // Remove an element from the window.
        auto remove = [&](int val) {
            auto it = low.find(val);

            // Check whether element exists in low.
            if (it != low.end()) {
                low.erase(it);
                sum1 -= val;
            }
            else {
                // Otherwise, remove it from high.
                it = high.find(val);
                high.erase(it);
                sum2 -= val;
            }

            balance();
        };

        // Calculate minimum operations for every window of size x.
        for (int i = 0; i < n; i++) {
            // Add current element.
            add(nums[i]);

            // Remove element that is outside the sliding window.
            if (i >= x) {
                remove(nums[i - x]);
            }

            // A complete window of size x is formed.
            if (i >= x - 1) {

                // Median minimizes the sum of absolute differences.
                long long median = *low.rbegin();

                // Cost of converting smaller elements to median.
                long long left = median * low.size() - sum1;

                // Cost of converting larger elements to median.
                long long right = sum2 - median * high.size();

                // Store minimum cost for this window.
                cost.push_back(left + right);
            }
        }

        // Number of possible windows.
        int m = cost.size();

        // Initialize DP with -1 (uncomputed states).
        dp.assign(m + 1, vector<long long>(k + 1, -1));

        // Find minimum cost to select k non-overlapping windows.
        return solve(0, k);
    }
};