class Solution
{
    public:
        int minSubarray(vector<int> &nums, int p)
        {
            int n = nums.size();
            long long total = 0;
            for (int x: nums) total += x;

            int need = total % p;
            if (need == 0) return 0;
            unordered_map<int, int> mp;
            mp[0] = -1;
            long long pref = 0;
            int ans = n;

            for (int i = 0; i < n; i++)
            {
                pref += nums[i];
                int curr = pref % p;
                int target = (curr - need + p) % p;
                if (mp.count(target))
                {
                    ans = min(ans, i - mp[target]);
                }
                mp[curr] = i;
            }

            return ans == n ? -1 : ans;
        }
};